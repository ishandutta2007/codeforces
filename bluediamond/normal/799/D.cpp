#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=100000+5;
ll n;
ll na,nb;
ll a,b;
ll v[N];

bool viz[N];

bool ok(ll cnt) {
    if(a>=na) {
        ll cur=b;
        for(ll i=1;i<=cnt;i++) {
            cur*=v[i];
            if(cur>=nb) {
                return 1;
            }
        }
        return 0;
    }
    if(b>=nb) {
        ll cur=a;
        for(ll i=1;i<=cnt;i++) {
            cur*=v[i];
            if(cur>=na) {
                return 1;
            }
        }
        return 0;
    }
    for(ll i=1;i<N;i++) {
        viz[i]=0;
    }
    viz[1]=1;
    ll dep=(1LL<<60);
    for(ll itr=1;itr<=cnt;itr++) {
        ll x=v[itr];
        for(ll i=N-1;i>=1;i--) {
            if(viz[i]==0) {
                continue;
            }
            if(i*x<N) {
                viz[i*x]=1;
            }
            else {
                dep=min(dep,i*x);
            }
        }
    }
    ll ans=-1;
    for(ll i=1;i<N;i++) {
        if(viz[i]==0) {
            continue;
        }
        if(i*a>=na) {
            ans=i;
            break;
        }
    }
    if(ans==-1 && dep!=(1LL<<60)) {
        ans=dep;
    }
    if(ans==-1) {
        return 0;
    }
    ll prod=b;
    for(ll i=1;i<=cnt;i++) {
        prod*=v[i];
        ll gcd=__gcd(prod,ans);
        ans/=gcd;
        prod/=gcd;
        if(prod>=nb) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>na>>nb>>a>>b>>n;
    for(ll i=1;i<=n;i++) {
        cin>>v[i];
    }
    sort(v+1,v+n+1); reverse(v+1,v+n+1);
    if(a>=na && b>=nb) {
        cout<<"0\n";
        return 0;
    }
    swap(a,b);
    if(a>=na && b>=nb) {
        cout<<"0\n";
        return 0;
    }
    swap(a,b);
    n=min(n,40LL);
    if(ok(n)==0) {
        cout<<"-1\n";
        return 0;
    }
    ll r=0,pas=(1<<5);
    while(pas) {
        if(ok(r+pas)==0) {
            r+=pas;
        }
        pas/=2;
    }
    r++;
    int ans1=r;
    swap(na,nb);
    r=0,pas=(1<<5);
    while(pas) {
        if(ok(r+pas)==0) {
            r+=pas;
        }
        pas/=2;
    }
    r++;
    int ans2=r;
    cout<<min(ans1,ans2)<<"\n";
    return 0;
}
/**
**/