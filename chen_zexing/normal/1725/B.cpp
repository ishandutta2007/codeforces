#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n,d,now=0,ans=0;
        cin>>n>>d,d++;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,greater<int>());
        for(int i=1;i<=n;i++){
            int nd=d/a[i]+(d%a[i]>0);
            if(now+nd>n) break;
            else ans++,now+=nd;
        }
        printf("%d\n",ans);
    }
    return 0;
}