#include <bits/stdc++.h>
using namespace std;
string s,s1;
bool used[300];
map<char,char> cd;
vector<pair<char,char> > v;
void no(){
    cout<<"-1";
    exit(0);
}

int main(){
    cin>>s>>s1;
    for (int i=0;i<s.size();++i){
        char x=s[i],y=s1[i];
        if (used[x]==true){
            if (cd[x]!=y) no();
        } else {
            used[x]=true;
            cd[x]=y;
            if (x!=y) v.push_back(make_pair(x,y));
        }
        if (used[y]==true){
            if (cd[y]!=x) no();
        } else {
            used[y]=true;
            cd[y]=x;
        }
    }
    cout<<v.size()<<'\n';
    for (int i=0;i<v.size();++i)
        cout<<v[i].first<<" "<<v[i].second<<'\n';
}