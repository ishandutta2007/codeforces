#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005],pos[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[i]=0;
        for(int i=n;i;i--){
            if(pos[a[i]]){
                ans=i;
                break;
            }
            pos[a[i]]=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}