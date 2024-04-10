#include <bits/stdc++.h>
using namespace std;

int n;
long long a,b,t;
int ans;
long long last;
string s;
long long dp[500005];

inline bool chek(int l,int r,long long last){
    if (l<=r) return false;
    if (dp[l]+last>t) return false;
    long long res=last+dp[l]+(r-1)*a;
    res=min(res,last+dp[l]+(n-l+1)*a);
    if (res<=t) ans=max(ans,r+(n-l+1));
    return res<=t;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>a>>b>>t;
    cin>>s;
    for (int i=n;i>1;--i) {
        last+=a;
        if (s[i-1]=='w') last+=b;
        last++;
        dp[i]=last;
    }
    last=0;
    for (int i=1;i<=n;++i) {
        if (i>1) last+=a;
        last++;
        if (s[i-1]=='w') last+=b;
        if (last>t) break;
        ans=max(ans,i);
        int l=i+1;
        int r=n;
        while (l<r-1) {
            int mid=(l+r)/2;
            if (chek(mid,i,last)) r=mid;
            else l=mid;
        }
        chek(l,i,last);
        chek(r,i,last);
    }
    cout<<ans;
}