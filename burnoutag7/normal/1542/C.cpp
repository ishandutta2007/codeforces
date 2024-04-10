#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

ll gcd(ll a,ll b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}

ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a/g*b;
}

ll n,p[105],r[105],ans;
int m;

void mian(){
    ans=0;
    cin>>n;
    p[0]=1;
    for(int i=1;;i++){
        p[i]=lcm(p[i-1],i);
        if(p[i]>n){
            m=i-1;
            break;
        }
    }
    for(int i=m;i>=1;i--){
        r[i]=n/p[i];
        for(int j=i+1;j<=m;j++)r[i]-=r[j];
        ans+=r[i]*(i+1)%mod;
    }
    cout<<ans%mod<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}