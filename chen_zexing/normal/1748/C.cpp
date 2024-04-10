#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long pre[200005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
        map <long long,int> mp;
        int ans=0,f=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                int mx=0;
                for(auto t:mp) mx=max(mx,t.second);
                if(f) ans+=mx;
                else ans+=mp[0];
                f=1,mp.clear(),mp[pre[i]]++;
            }
            else mp[pre[i]]++;
        }
        int mx=0;
        for(auto t:mp) mx=max(mx,t.second);
        if(f) ans+=mx;
        else ans+=mp[0];
        printf("%d\n",ans);
    }
    return 0;
}