#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1000000007;

ll n,m;

vector<vector<ll> > mul(const vector<vector<ll> > & a,const vector<vector<ll> > & b){
    vector<vector<ll> > res(m,vector<ll>(m,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                res[i][j]=(res[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
    return res;
}

vector<vector<ll> > pow(vector<vector<ll> > a,ll N){
    vector<vector<ll> > res(m,vector<ll>(m,0));
    for(int i=0;i<m;i++){
        res[i][i]=1;
    }
    while(N>0){
        if(N&1){
            res=mul(res,a);
        }
        a=mul(a,a);
        N>>=1;
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    if(n<m){
        cout<<1<<endl;
        return 0;
    }
    vector<vector<ll> > t(m,vector<ll>(m,0));
    t[0][0]=1;
    t[0][m-1]=1;
    for(int i=0;i+1<m;i++){
        t[i+1][i]=1;
    }
    t=pow(t,n-m);
    ll ans=0;
    ans+=t[0][0]*2;
    for(int i=1;i<m;i++){
        ans+=t[0][i];
    }
    cout<<ans%mod<<endl;

    return 0;
}