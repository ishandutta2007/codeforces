#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,t,m=-1;
    cin>>n>>m;
    ll a[n+1];a[0]=0;a[n]=0;
    for(ll i=1;i<n;i++){
        cin>>t;
        if(m>t)a[i]=m-t;
        else {a[i]=0;m=t;}
    }
    set<ll> s;
    m=-1,t=0;
    for(ll i=0;i<=n;i++){
        if(m==a[i])continue;
        m=a[i];
        s.insert(m);
        set<ll>::iterator j=s.end();
        j--;
        while(m<*j){
            ll x,y;
            x=*j;
            s.erase(j);
            j=s.end();j--;
            y=*j;
            t+=x-y;
        }
    }
    cout<<t;
}