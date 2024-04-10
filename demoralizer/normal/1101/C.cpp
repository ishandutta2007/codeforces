#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return ((a*t*t)%p);
    else return ((t*t)%p);
}


void solve(){
    int n;
    cin>>n;
    vc<pii> rs,ls,glo;vc<int> ans(n);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        rs.pb({r,i});
        ls.pb({l,i});
        glo.pb({l,r});
    }
    sort(ls.begin(),ls.end());
    sort(rs.begin(),rs.end(),greater<pii>());
    int l1=glo[0].fr,r1=glo[0].sc;
    ans[0]=1;
    for(int i=0;i<n;i++){
        pii k=glo[i];
        if(k.fr<=l1&&k.sc>=r1){
            l1=k.fr;r1=k.sc;ans[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        pii k=ls[i];
        if(k.fr>=l1&&k.fr<=r1){
            ans[k.sc]=1;
            r1=max(r1,glo[k.sc].sc);
        }
    }
    for(int i=0;i<n;i++){
        pii k=rs[i];
        if(k.fr<=r1&&k.fr>=l1){
            ans[k.sc]=1;
            l1=min(l1,glo[k.sc].fr);
        }
    }
    int f=0;
    for(int i=0;i<n;i++)if(ans[i]==0){ans[i]=2;f=1;}
    if(f)for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    else cout<<-1;
    cout<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}