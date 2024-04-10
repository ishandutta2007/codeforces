#include <bits/stdc++.h>
using namespace std;

string s;
int x,y;
map<pair<int,int>,bool> used;

int main() {
    cin>>s;
    used[make_pair(0,0)]=true;
    for (int i=0;i<s.size();++i) {
        int xx=x,yy=y;
        if (s[i]=='L') --x;
        else if (s[i]=='R') ++x;
        else if (s[i]=='U') ++y;
        else --y;
        if (used[make_pair(x,y)]) {
            cout<<"BUG";
            return 0;
        }
        for (int i=-1;i<=1;i+=2) {
            if (used[make_pair(x+i,y)] && xx!=x+i) {
                cout<<"BUG";
                return 0;
            }
            if (used[make_pair(x,y+i)] && yy!=y+i) {
                cout<<"BUG";
                return 0;
            }
        }
        used[make_pair(x,y)]=true;
    }
    cout<<"OK";
}