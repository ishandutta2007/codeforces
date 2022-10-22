#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20;
const int MOD=/*1000000007*/ 998244353;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=1;
    if(y%2) b=x;
    return pow(x*x%mod,a,mod)*b%mod;
}
string s,t,sp,tp;
ll m,ans,pf[1010],km[1010],sf[1010];
int main() {
    fast_io;
    cin >> s;
    cin >> m;
    sp=s;
    for(ll i=0; i<s.size(); i++) sp[i]=s[s.size()-i-1];
    while(m--){
        cin >> t;
        if(t.size()==1 || t.size()>s.size()) continue;
        fill(km,km+1010,0);
        fill(pf,pf+1010,1000000);
        fill(sf,sf+1010,-1000000);
        pf[0]=-1;
        sf[0]=1000000;
        ll k=0;
        for(ll i=1; i<t.size(); i++){
            while(t[k]!=t[i]){
                if(k!=0) k=km[k-1];
                else{
                    km[i]=0;
                    break;
                }
            }
            if(t[k]==t[i]) km[i]=++k;
        }
        ll i=0,j=0;
        while(i<s.size()){
            if(s[i]!=t[j] && j>0) pf[j]=min(pf[j],i-j),j=km[j-1];
            else if(s[i]!=t[j]) i++;
            else i++,j++;
            if(j==t.size()) pf[j]=min(pf[j],i-j),j=km[j-1];
        }
        tp=t;
        for(ll i=0; i<t.size(); i++) tp[i]=t[t.size()-i-1];
        fill(km,km+1010,0);
        k=0;
        for(ll i=1; i<t.size(); i++){
            while(tp[k]!=tp[i]){
                if(k!=0) k=km[k-1];
                else{
                    km[i]=0;
                    break;
                }
            }
            if(tp[k]==tp[i]) km[i]=++k;
        }
        i=0,j=0;
        while(i<sp.size()){
            if(sp[i]!=tp[j] && j>0) sf[j]=max(sf[j],(ll)s.size()-1-(i-j)),j=km[j-1];
            else if(sp[i]!=tp[j]) i++;
            else i++,j++;
            if(j==tp.size()) sf[j]=max(sf[j],(ll)s.size()-1-(i-j)),j=km[j-1];
        }
        for(ll i=t.size(); i>0; i--) pf[i-1]=min(pf[i-1],pf[i]),sf[i-1]=max(sf[i],sf[i-1]);
        for(ll i=0; i<=t.size(); i++) if(pf[i]+i-1<sf[t.size()-i]-((ll)t.size()-i-1)){
            ans++;
            break;
        }
    }
    cout << ans;
    return 0;
}