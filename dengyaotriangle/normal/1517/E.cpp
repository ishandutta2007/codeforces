#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;
const int mdn=998244353;

int n;
int a[maxn];
int dp[maxn];
long long pfx[maxn];
long long pf2[2][maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)pfx[i]=pfx[i-1]+a[i];
        pf2[1][1]=a[1];
        for(int i=3;i<=n;i+=2)pf2[1][i]=pf2[1][i-2]+a[i];
        for(int i=2;i<=n;i+=2)pf2[0][i]=pf2[0][i-2]+a[i];
        int tans=0;
        for(int i=n;i>=0;i--){
            if(pfx[i]-pfx[n]+pfx[i]>0)tans++;
        }
        //cerr<<tans<<endl;
        for(int i=2;i<=n;i++){
            long long tls=pfx[n]-pfx[i-1]-pfx[i-1];
            for(int k1=0;k1<2;k1++){
                for(int k2=0;k2<2;k2++){
                    if(k1&&i==n)continue;
                    if(k2&&i==2)continue;
                    long long ls=tls;
                    int lb=0,rb=(n-i+1)/2,ans=-1;
                    if(k1){
                        ls-=2*a[n];
                        if((n-i+1)&1)rb=(n-i-1)/2;
                        else rb=(n-i-3)/2;
                    }
                    if(k2)ls+=2*a[1];
                    while(lb<=rb){
                        int m=(lb+rb)/2;
                        long long dlt=pf2[(i-1)&1][i+2*m-1]-pf2[(i-1)&1][i-1];
                        if(ls-2*dlt>0){
                            ans=m;lb=m+1;
                        }else{
                            rb=m-1;
                        }
                    }
                    tans=(tans+ans+1)%mdn;
                    //cerr<<i<<' '<<k1<<' '<<k2<<':'<<tans<<endl;
                }
            }
        }
        cout<<tans<<'\n';
    }
    return 0;
}