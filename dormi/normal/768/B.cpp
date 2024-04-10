#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
map<lli,lli> dep;
int go(lli a, lli l, lli r){
    if(r<l)return 0;
    if(a<=1)return a;
    lli leftam=((lli)1<<(dep[a]))-(lli)1;
    if(leftam>=r)return go(a/(lli)2,l,r);
    if(leftam+(lli)2<=l)return go(a/(lli)2,l-leftam-(lli)1,r-leftam-(lli)1);
    return (a%(lli)2)+go(a/(lli)2,l,min(r,leftam))+go(a/(lli)2,(lli)1,r-leftam-(lli)1);
}
lli ca(lli loc){
    if(loc<=1)return dep[loc]=0;
    return dep[loc]=ca(loc/2)+1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,l,r;
    cin>>n>>l>>r;
    ca(n);
    printf("%d\n",go(n,l,r));
    return 0;
}