#include <bits/stdc++.h>
using namespace std;
int n,x,y;
string s;
inline void no(int x){
    cout<<"Controller ";
    cout<<x;
    exit(0);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x>>y;
    cin>>s>>s;
    int dir;
    if (s=="head") dir=0;
    else dir=1;
    cin>>s;
    if (x==y) {
        cout<<"Controller 0";
        return 0;
    }
    for (int i=0;i<s.size();++i) {
        if (s[i]=='0') {
            if (dir==0 && x>1 && x<y) --x;
            else if (dir==0 && x<n && x>y) ++x;
            else if (dir==1 && x<n && x>y) ++x;
            else if (dir==1 && x>1 && x<y) --x;
            if (x==y) no(i+1);
            if (dir==0) --y;
            else ++y;
            if (y==1 || y==n) dir=1-dir;
            if (x==y) no(i+1);
        } else {
            if (dir==0) --y;
            else ++y;
            if (y==1 || y==n) dir=1-dir;
            if (y==1) x=n;
            else if (y==n) x=1;
            else if (dir==0) x=n;
            else x=1;
            if (x==y) no(i+1);
        }
    }
    cout<<"Stowaway";
}