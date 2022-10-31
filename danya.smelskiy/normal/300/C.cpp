#include <bits/stdc++.h>
using namespace std;

long long x,y,n,a[1000001];
long long ans;
inline bool chek(long long sum){
    while (sum>0){
        if (sum%10!=x && sum%10!=y) return false;
        sum/=10;
    }
    return true;
}

inline unsigned long long take(unsigned long long xx){
    unsigned long long r=1;
    xx%=1000000007;
    unsigned long long nn=1000000005;
    while (nn>0){
        if (nn & 1){
            r*=xx%1000000007;
            r%=1000000007;
        }
        xx*=xx%1000000007;
        xx%=1000000007;
        nn>>=1;
    }
    return r%1000000007;
}
int main(){
    cin>>x>>y>>n;
    a[1]=1;
    for (int i=2;i<=n;++i){
        a[i]=((a[i-1]*i)%1000000007);
    }
    for (int i=0;i<=n;++i){
        long long sum=i*x+(n-i)*y;
        if (chek(sum)==true){
            if (i==n || i==0) ans++;
            else {

                ans+=(a[n])*take(a[i]*a[n-i])%1000000007;
                ans%=1000000007;
            }
        }
    }
    cout<<ans;
}