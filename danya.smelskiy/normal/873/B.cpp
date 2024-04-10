#include <bits/stdc++.h>
using namespace std;

int n;
string s;
long long ans;
map<int,int> kol;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    int ss=0;
    kol[0]=0;
    for (int i=1;i<=n;++i) {
        ss+=(s[i-1]=='1' ? 1 : -1);
        if (kol[ss]) ans=max(ans,(long long)i-kol[ss]);
        if (!ss) ans=i;
        if (ss && !kol[ss]) kol[ss]=i;
    }
    cout<<ans;
}