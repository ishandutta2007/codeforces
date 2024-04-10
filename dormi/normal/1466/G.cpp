#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MS=6e6+1,ML=1e6,MN=1e5+2;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
string sx[20];
int kmp[MS];
ll suf[MN][26],p2[MN],inv[MN];
int getoccur(const string &a, const string &b){//number of times a appears in b
    string s=a+"$"+b;
    int ans=0;
    for(int i=1,j=0;i<sz(s);i++){
        while(j>0&&s[j]!=s[i])j=kmp[j-1];
        if(s[i]==s[j])j++;
        if((kmp[i]=j)>=sz(a))ans++;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    string t;
    cin>>sx[0]>>t;
    for(int i=1;sz(sx[i-1])<ML&&i<=n;i++)sx[i]=sx[i-1]+t[i-1]+sx[i-1];
    p2[0]=inv[0]=1;
    for(int i=1;i<=n;i++)p2[i]=p2[i-1]*ll(2)%mod,inv[i]=fp(p2[i],mod-2);
    for(int i=n;i>=0;i--){
        for(int j=0;j<26;j++)suf[i][j]=suf[i+1][j];
        suf[i][t[i-1]-'a']=(suf[i][t[i-1]-'a']+p2[n-i])%mod;
    }
    int k;
    string a;
    while(q--){
        cin>>k>>a;
        int lo=0;
        while(lo<=n&&sz(sx[lo])<sz(a))lo++;
        if(lo>k){
            printf("0\n");
            continue;
        }
        ll am=getoccur(a,sx[lo]);
        ll ans=am*p2[k-lo]%mod;
        for(int i=0;i<26;i++){
            ll te=getoccur(a,sx[lo]+char('a'+i)+sx[lo])-2*am;
            if(te&&suf[lo + 1][i] - suf[k + 1][i]){
                ans += (suf[lo + 1][i] - suf[k + 1][i] + mod) * inv[n - k] % mod * te%mod;
                if(ans>=mod)ans-=mod;
            }
        }
        printf("%lli\n",ans);
    }
    return 0;
}