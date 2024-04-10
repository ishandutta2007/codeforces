#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1000000007;

int n,k;
string s;
int BS[1000005],WS[1000005];
ll LM[1000005],BF[1000005],RM[1000005],WF[1000005];
ll ans,pw2;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n;i++){
        BS[i+1]=BS[i]+(s[i]=='B');
        WS[i+1]=WS[i]+(s[i]=='W');
    }
    BF[0]=1;
    for(int i=1;i<=n;i++){
        if(i>=k&&WS[i]-WS[i-k]==0){
            if(i==k||s[i-k-1]!='B'){
                LM[i]=BF[max(i-k-1,0)];
            }
        }
        ll tmp=BF[i-1];
        if(s[i-1]=='X')tmp=tmp*2%mod;
        tmp=(tmp-LM[i]+mod)%mod;
        BF[i]=tmp;
    }
    WF[n]=1;
    for(int i=n-1;i>=0;i--){
        if(i<=n-k&&BS[i+k]-BS[i]==0){
            if(i==n-k||s[i+k]!='W'){
                RM[i]=WF[min(i+k+1,n)];
            }
        }
        ll tmp=WF[i+1];
        if(s[i]=='X')tmp=tmp*2%mod;
        tmp=(tmp-RM[i]+mod)%mod;
        WF[i]=tmp;
    }
    pw2=1;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='X')pw2=pw2*2%mod;
        ll cw=(pw2-WF[i]+mod)%mod;
        ans=(ans+LM[i]*cw)%mod;
    }
    cout<<ans<<endl;

    return 0;
}