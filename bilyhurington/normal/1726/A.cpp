#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<vector>
using namespace std;
int n,a[2010],b[2010];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int Maxn=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) b[j%n+1]=a[j];
        for(int j=1;j<=n;j++) a[j]=b[j];
        Maxn=max(Maxn,a[n]-a[1]);
    }//printf("%d\n",Maxn);
    int maxn=0,minn=2e9;
    // for(int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
    for(int i=1;i<=n;i++){
        if(i<n) minn=min(minn,a[i]);
        if(i>1) maxn=max(maxn,a[i]);
    }
    printf("%d\n",max(Maxn,max(maxn-a[1],a[n]-minn)));
}
int main(){int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}