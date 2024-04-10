#include <bits/stdc++.h>
using namespace std;

long long n,ans,x,y;
map<long long,long long> kol;
map<pair<long long,long long>,long long> o;
map<long long,long long> kol2;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        ans+=kol[x];
        ans+=kol2[y];
        ans-=o[make_pair(x,y)];
        ++kol[x];
        ++o[make_pair(x,y)];
        kol2[y]++;
    }
    cout<<ans;
}