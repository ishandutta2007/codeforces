#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> v,pref;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.pb(a);
        if(i==0)pref.pb(a);
        else pref.pb(pref[i-1]+a);
    }
    int mi=1e8+10;
    for(int i=1;i<N;i++){
        for(int j=i;j<N && (j-i+1)*(j-i+1)<mi;j++){
            mi=min(mi,(j-i+1)*(j-i+1)+(pref[j]-pref[i-1])*(pref[j]-pref[i-1]));
        }
    }
    cout<<mi;
}