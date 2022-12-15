#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005],nxt[100005],stk[100005],pre[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,q,h=0;
        cin>>n>>q;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=max(a[i],pre[i-1]);
        for(int i=n;i;i--){
            while(h&&a[stk[h]]<a[i]) h--;
            nxt[i]=h?stk[h]:n+1;
            stk[++h]=i;
        }
        for(int i=1,x,t;i<=q;i++){
            scanf("%d%d",&x,&t);
            if(a[x]==n) printf("%d\n",max(0,t-(x-1)+(x!=1)));
            else if(pre[x]>a[x]) puts("0");
            else printf("%d\n",min(max(0,t-(x-1)+(x!=1)),nxt[x]-x-(x==1)));
        }
    }
    return 0;
}