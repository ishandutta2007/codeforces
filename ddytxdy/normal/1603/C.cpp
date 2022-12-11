#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
using namespace std;
const int N=2e5+50,mod=998244353;
int T,n,a[N],ans;
vector<int>v[N],vv[N],vvv[N];
void nong(int i){
    for(int l=1,r;l<=a[i];l=r+1){
        int d=a[i]/l;r=a[i]/d;
        v[i].pb(d);vv[i].pb(d==a[i]),vvv[i].pb(l);
    }
}
void erase(int i){
    vector<int>().swap(v[i]);
    vector<int>().swap(vv[i]);
    vector<int>().swap(vvv[i]);
}
void solve(){
    scanf("%d",&n);ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    nong(n);
    for(int i=n-1;i;i--){
        nong(i);
        for(int j=0,k=0;j<v[i+1].size();j++){
            int num=0;
            while(v[i][k]+(a[i]%v[i][k]!=0)>v[i+1][j])k++;
            if(a[i]%v[i+1][j]==0)num=a[i]/v[i+1][j]-1;
            else num=vvv[i][k]-1;
            ans=(ans+1ll*vv[i+1][j]*num%mod*i)%mod;
            // if(i==1)cout<<v[i+1][j]<<" "<<vv[i+1][j]<<endl;
            vv[i][k]+=vv[i+1][j];
        }
        erase(i+1);
        // cout<<i<<" "<<ans<<endl;
    }
    erase(1);
    cout<<ans<<endl;
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}