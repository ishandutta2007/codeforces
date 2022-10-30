#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
string s;
long long f[200005];
long long r[200005];
int dp[200005];
long long pow(long long x,long long y){
    long long res=1;
    while (y){
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
long long get(int x,int y){
    long long res=f[x];
    if (x<y) return 0;
    res=(res*r[y])%md;
    res=(res*r[x-y])%md;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    f[0]=1;
    r[0]=1;
    int n=s.size();
    for (int i=1;i<=200000;++i){
        f[i]=(f[i-1]*i)%md;
        r[i]=pow(f[i],md-2);
    }
    for (int i=1;i<=n;++i){
        dp[i]+=dp[i-1];
        if (s[i-1]=='(') ++dp[i];
    }
    int last=0;
    long long ans=0;
    for (int i=n;i>0;--i){
        if (s[i-1]==')') {
            ++last;
            ans=(ans+get(last+dp[i]-1,last))%md;
        }
    }
    cout<<ans;
}