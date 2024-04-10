#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
const int N=1e6+6,INF=1e9;
int a[N],b[N],q[N],mn[N];
int main(){
    int T; cin>>T;
    while (T--){
        int n,m,k; cin>>n>>m>>k;
        k=min(k,--m);
        for (int i=1;i<=n;++i) scanf("%d",&a[i]);
        for (int i=1;i<=n;++i) b[i]=max(a[i],a[i+(n-m)-1]);
        int len=m-k+1,l=1,r=0;
        for (int i=1;i<=n;++i){
            while (l<=r&&i-q[l]+1>len) ++l;
            while (l<=r&&b[q[r]]>b[i]) --r;
            q[++r]=i;
            mn[i]=b[q[l]];
        }
        int ans=0;
        for (int i=0;i<=k;++i){
            int r=n-(k-i);
            ans=max(ans,mn[i+len]);
        }
        cout<<ans<<endl;
    }
}