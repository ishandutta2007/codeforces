#include <bits/stdc++.h>
using namespace std;


long long n,x,y,z,k;
long long ans;
map<pair<long long,long long>,long long> used;
map<pair<long long,long long>,long long> kol;
void update(long long x,long long y,long long k,long long z){
    if (!x) return;
    if (used[make_pair(x,y)]!=z) {
        kol[make_pair(x,y)]+=k;
        used[make_pair(x,y)]=z;
    } else kol[make_pair(x,y)]-=k;
    update(x/2,x,k,z);
}
void get(long long x,long long y,long long k){
    if (!x) return;
    if (used[make_pair(x,y)]!=k) ans+=kol[make_pair(x,y)];
    else ans-=kol[make_pair(x,y)];
    used[make_pair(x,y)]=k;
    get(x/2,x,k);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        if (x==1) {
            cin>>y>>z>>k;
            update(y/2,y,k,i);
            update(z/2,z,k,i);
        } else {
            cin>>y>>z;
            ans=0;
            get(y/2,y,i);
            get(z/2,z,i);
            cout<<ans<<'\n';
        }
    }
}