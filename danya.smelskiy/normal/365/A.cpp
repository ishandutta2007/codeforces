#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
bool f[15];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s;
        bool t=false;
        for (int j=0;j<=9;++j)
            f[j]=false;
        for (int j=0;j<s.size();++j)
         f[s[j]-'0']=true;
        for (int j=0;j<=9;++j)
        if ((j<=m && f[j]==false) ) t=true;
        if (t==false) ++ans;
    }
    cout<<ans;
}