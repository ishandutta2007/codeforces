#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
string s;
int main(){
    cin>>n>>m;
    cin>>s;
    for (int j=0;j<s.size();++j)
        if (s[j]=='.' && s[j-1]=='.') ++ans;
    for (int i=1;i<=m;++i){
        char c;
        int x;
        cin>>x>>c;
        if (s[x-1]=='.' && c!='.'){
            if (s[x-2]=='.') --ans;
            if (s[x]=='.') --ans;
            s[x-1]='x';
        } else if (c=='.' && s[x-1]!='.'){
            if (s[x-2]=='.') ++ans;
            if (s[x]=='.') ++ans;
            s[x-1]='.';
        }
        cout<<ans<<'\n';
    }
}