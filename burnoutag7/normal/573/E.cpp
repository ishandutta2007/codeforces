#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","tree-vectorize","opt-info","fast-math")
#pragma GCC target("sse,sse2,sse3,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a,f[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(f,0xc0,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int j=i;j;j--)f[j]=max(f[j],f[j-1]+a*j);
    }
    cout<<*max_element(f,f+1+n);

    return 0;
}