#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll chk(const string &a,int s){
    int n=a.size();
    vector<ll> v(n+1),pw(n+1);
    for(int i=0;i<10;i++)if(s>>i&1){
        v[1]=i;
        break;
    }
    pw[0]=1;pw[1]=10;
    for(int i=2;i<=n;i++){
        v[i]=v[i-1]*10+v[1];
        pw[i]=pw[i-1]*10;
    }
    ll prv=0,ans=LLONG_MAX;
    for(int i=0;i<n;i++){
        for(int j=a[i]-'0'+1;j<10;j++)if(s>>j&1){
            ans=min(ans,prv+pw[n-i-1]*j+v[n-i-1]);
            break;
        }
        if(s>>a[i]-'0'&1^1){
            return ans;
        }
        prv+=pw[n-i-1]*(a[i]-'0');
    }
    return prv;
}

int n,k;

void mian(){
    cin>>n>>k;
    ll ans=1;
    while(ans<n){
        ans*=10;
        ans+=k==1;
    }
    string N=to_string(n);
    for(int s=0;s<1<<10;s++)if(__builtin_popcount(s)==k){
        ans=min(ans,chk(N,s));
    }
    cout<<ans<<'\n';
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