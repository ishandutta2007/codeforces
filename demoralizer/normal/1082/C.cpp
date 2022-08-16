#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
pair<ll, vc<ll> > s[100009];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,m;
    cin>>n>>m;
    set<ll> kkk;
    for(int i=0;i<m;i++)s[i].fr=0;
    for(ll i=1;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        s[a].fr++;
        kkk.insert(a);
        s[a].sc.pb(b);
    }
    sort(s,s+m);
    reverse(s,s+m);
    m=kkk.size();
    ll z=0;
    for(ll i=0;i<m;i++){
        sort(s[i].sc.begin(),s[i].sc.end(),greater<ll>());
        for(ll j=1;j<s[i].fr;j++) s[i].sc[j]+=s[i].sc[j-1];
        for(ll j=0;j<s[i].fr;j++) if(s[i].sc[j]<0)s[i].sc[j]=0;
        if(s[i].fr>z)z=s[i].fr;
    }
    ll maxx=0;
    /*/checker
    cout<<"-------------\n";
    for(ll i=1;i<=z;i++){
        //cout<<(i+1)<<"--->"<<s[i].fr<<"\n";
        for(ll j=0;j<m;j++){
            if(s[j].fr<i)break;
            cout<<s[j].sc[i-1]<<"\t";
        }
        cout<<"\n";
    }
    cout<<z;
    cout<<"\n-------------\n";
    //checker*/
    for(ll i=1;i<=z;i++){
        ll t=0;
        for(ll j=0;j<m;j++){
            if(s[j].fr<i)break;
            t+=s[j].sc[i-1];
        }
        if(t>maxx)maxx=t;
    }
    cout<<maxx;
}