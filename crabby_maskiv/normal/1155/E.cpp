#include <bits/stdc++.h>
#define inv(x) po(x,mod-2)
using namespace std;
typedef long long ll;
const int N=25;
const ll mod=1000003;
int n,m;
ll po(ll x,int k){
    if(k==0) return 1;
    ll sum=po(x,k/2);
    if(k&1) return ((sum*sum)%mod*x)%mod;
    else return (sum*sum)%mod;
}
int a[N][N];
int len;
void gauss(){
    int i,j,k;
    for(i=1;i<=len;i++){
        ll f=a[len+1][i]*inv(a[i][i])%mod;
        for(j=i;j<=n+1;j++)
            a[len+1][j]-=(f*a[i][j])%mod;
    }
    if(a[len+1][len+1])
        len++;
    return;
}
ll s[N];
int main() {
    srand((unsigned)time(0));
    int i,j;
    n=11;
    for(i=1;i<=50;i++){
        ll q=(rand()*32768ll+rand())%mod;
        cout<<"? "<<q<<endl;
        fflush(stdout);
        ll ans;cin>>ans;
        ll tmp=1;
        for(j=1;j<=n;j++){
            a[len+1][j]=tmp;
            tmp*=q;tmp%=mod;
        }
        a[len+1][n+1]=ans;
        gauss();
        if(len==11) break;
    }
    for(i=n;i>0;i--){
        ll f=(a[i][n+1]*inv(a[i][i]))%mod;
        s[i]=f;
        for(j=i-1;j>0;j--)
            a[j][n+1]-=(f*a[j][i])%mod;
    }
    for(i=0;i<mod;i++){
        ll sum=0,tmp=1;
        for(j=1;j<=n;j++){
            sum+=s[j]*tmp;sum%=mod;
            tmp*=i;tmp%=mod;
        }
        if(!sum){
            cout<<"! "<<i<<endl;
            fflush(stdout);
            return 0;
        }
    }
    cout<<"! -1"<<endl;
    fflush(stdout);
    return 0;
}