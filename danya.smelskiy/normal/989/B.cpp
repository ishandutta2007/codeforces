#include <bits/stdc++.h>
using namespace std;


int n,m;
string s;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s;
    bool t=false;
    for (int i=1;i<=m;++i) {
        vector<int> v;
        v.clear();
        for (int j=i;j<=n;j+=m)
            v.push_back(j-1);
        if (v.size()==1) {
            int x=v[0];
            if (s[x]=='.') s[x]='0';
            continue;
        }
        bool tt=false;
        for (int j=0;j<v.size();++j) {
            int x=v[j];
            if (s[x]!='.') continue;
            if (j) {
                int y=v[j-1];
                if (s[y]=='0') s[x]='1';
                else s[x]='0';
                tt=true;
            }
            if (j+1<v.size()) {
                int y=v[j+1];
                if (s[y]=='0') s[x]='1',tt=true;
                else if (s[y]=='1') s[x]='0',tt=true;
                else s[x]='1';
            }
        }
        for (int j=1;j<v.size();++j) {
            int x=v[j-1];
            int y=v[j];
            if (s[x]!=s[y]) tt=true;
        }
        t|=tt;
    }
    if (!t) cout<<"No";
    else cout<<s;
}