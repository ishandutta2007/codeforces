#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],w[200005],nxt[200005],pos[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),w[i]=1,pos[i]=n+1;
        for(int i=n;i;i--) nxt[i]=pos[a[i]],pos[a[i]]=i;
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        int fl=1;
        for(int i=1,x=1;i<=n;i++) {
            if(b[i]==a[x]){
                w[x]--;
                if(!w[x]) x++;
            }
            else{
                if(nxt[x]!=n+1){
                    w[nxt[x]]+=w[x];
                    x++,i--;
                }
                else{
                    fl=0;
                    break;
                }
            }
        }
        puts(fl?"YES":"NO");
    }
    return 0;
}