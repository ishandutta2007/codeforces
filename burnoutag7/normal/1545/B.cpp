#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;
const int precLen=100000;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int fact[precLen+5],inv[precLen+5];

ll C(int n,int r){
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

void initialization(){
    fact[0]=1;
    for(int i=1;i<=precLen;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
    }
    inv[precLen]=qpow(fact[precLen],mod-2);
    for(int i=precLen-1;i>=0;i--){
        inv[i]=(ll)inv[i+1]*(i+1)%mod;
    }
}

int n;

void mian(){
    cin>>n;
    string s;
    cin>>s;
    {
        int p1=0;
        while(p1<n&&s[p1]=='1')p1++;
        if(p1==n){
            cout<<"1\n";
            return;
        }
        if(p1&1){
            s.erase(s.begin());
            n--;
        }
    }
    {
        int p1=0;
        while(p1<n&&s[n-p1-1]=='1')p1++;
        if(p1&1){
            s.pop_back();
            n--;
        }
    }
    int nz=0,ns=0,nd=0;//zero, single, double
    int clen=0;
    for(char c:s){
        if(c=='1'){
            clen++;
        }else{
            if(clen&1)ns++;
            nd+=clen/2;
            clen=0;
        }
    }
    if(clen&1)ns++;
    nd+=clen/2;
    nz=n-ns-nd*2;
    if(!ns){
        cout<<C(nz+nd,nz)<<'\n';
        return;
    }
    ll ans=0;
    for(int i=0;i<=nd;i++){
        ans=(ans+C(nz-ns+i,nz-ns)*C(nd-i+ns-1,ns-1))%mod;
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initialization();

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}