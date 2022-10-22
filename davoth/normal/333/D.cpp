#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
const ll MAX_N=1e3+10;
ll a[MAX_N][MAX_N],n,m;
bool check(ll k){
    bool b[MAX_N][MAX_N];
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(a[i][j]>=k) b[i][j]=1;
            else b[i][j]=0;
        }
    }
    bool c[MAX_N][MAX_N];
    for(ll i=0; i<MAX_N; i++) for(ll j=0; j<MAX_N; j++) c[i][j]=0;
    vector<ll> v[m];
    for(ll i=0; i<m; i++){
        for(ll j=0; j<n; j++){
            if(b[j][i]==1) v[i].push_back(j);
        }
    }
    for(ll i=0; i<m; i++){
        for(ll j=0; j<v[i].size(); j++){
            for(ll p=j+1; p<v[i].size(); p++){
                if(c[v[i][j]][v[i][p]]==0) c[v[i][j]][v[i][p]]=1;
                else return true;
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll mx=-1,mn=1e9+10;
    cin >> n >> m;
    for(ll i=0; i<n; i++) for(ll j=0; j<m; j++){
        cin >> a[i][j];
        if(a[i][j]<mn) mn=a[i][j];
        if(a[i][j]>mx) mx=a[i][j];
    }
    ll l=mn,r=mx+1;
    while(r-l>1){
        ll md=(r+l)/2;
        if(check(md)) l=md;
        else r=md;
    }
    cout << l;
	return 0;
}