#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli mod=998244353;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k,n;
    cin>>n>>k;
    vector<int> inds;
    lli a;
    lli sum=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>n-k)inds.push_back(i),sum+=a;
    }
    printf("%lli ",sum);
    int last=inds[0];
    lli am=1;
    for(int i=1;i<sz(inds);i++){
        am=am*(lli)(inds[i]-last)%mod;
        last=inds[i];
    }
    printf("%lli\n",am);
    return 0;
}