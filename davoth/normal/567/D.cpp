#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a,m,ar[(ll)2e5+10];
bool check(ll mv){
    ll am[mv+2],cnt=0;
    am[mv+1]=n+1;
    am[0]=0;
    for(ll i=1; i<=mv; i++) am[i]=ar[i-1];
    sort(am,am+mv+2);
    for(ll i=0; i<mv+1; i++){
        ll t=am[i+1]-am[i]-1,te=t/a;
        while(t-te*a<te-1) --te;
        cnt+=te;
    }
    return cnt>=k;
}
int main()
{
    cin >> n >> k >> a >> m;
    for(ll i=0; i<m; i++) cin >> ar[i];
    ll l=0,r=m+1;
    while(r-l>1){
        ll mid =(r+l)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    if(l==m) cout << -1;
    else cout << r;
    return 0;
}