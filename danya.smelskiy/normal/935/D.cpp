#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int dp1[100005];
int dp2[100005];
int a[100005];
int b[100005];

long long n,m;

inline long long pw(long long x,int y) {
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}

inline long long f(long long x) {
    long long xx=x;
    long long yy=x-1;
    if (xx&1) yy>>=1;
    else xx>>=1;
    return (xx*yy)%md;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    int pos=1;
    while (pos<=n) {
        if (a[pos]!=0 && b[pos]!=0) {
            if (a[pos]==b[pos]) {
                ++pos;
                continue;
            }
            if (a[pos]>b[pos]) {
                cout<<"1";
                return 0;
            } else {
                cout<<"0";
                return 0;
            }
        }
        break;
    }
    if (pos>n) {
        cout<<"0";
        return 0;
    }
    for (int i=n;i>0;--i) {
        dp1[i]=dp1[i+1];
        if (a[i]==0) ++dp1[i];
        dp2[i]=dp2[i+1];
        if (b[i]==0) ++dp2[i];
    }
    long long cnt=1;
    long long ans=0;
    long long zz;
    long long z;
    for (int i=pos;i<=n;++i) {
        if (a[i]!=0 && b[i]!=0) {
            if (a[i]==b[i]) continue;
            if (a[i]<b[i]) break;
            z=(pw(m,dp1[i+1])*pw(m,dp2[i+1]))%md;
            z=(z*cnt)%md;
            ans+=z;
            if (ans>=md) ans-=md;
            break;
        }
        if (a[i]==0 && b[i]==0) {
            z=(pw(m,dp1[i+1])*pw(m,dp2[i+1]))%md;
            z=(z*cnt)%md;
            z=(z*f(m))%md;
            ans+=z;
            if (ans>=md) ans-=md;
            cnt=(cnt*m)%md;
            continue;
        } else {
            if (a[i]==0) zz=m-b[i];
            else zz=a[i]-1;
            z=(pw(m,dp1[i+1])*pw(m,dp2[i+1]))%md;
            z=(z*cnt)%md;
            z=(z*zz)%md;
            ans+=z;
            if (ans>=md) ans-=md;
        }
    }
    long long ans2=(pw(m,dp1[1])*pw(m,dp2[1]))%md;
    ans2=pw(ans2,md-2);
    ans=(ans*ans2)%md;
    cout<<ans;
}