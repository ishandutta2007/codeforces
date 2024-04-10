#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second

ll n,k,a[100000],b,i,ans=1,p=1;

ll upp(ll x,ll y) {
	return (x%y?x/y+1:x/y);
}

int main(){
    cin >> n >> k;
    F0R(i,n/k) cin >> a[i];
    F0R(i,k) p *= 10;
    F0R(i,n/k) {
    	cin >> b;
    	ans *= upp(p,a[i])-upp((b+1)*p/10,a[i])+upp(b*p/10,a[i]);
    	ans %= 1000000007;
    }
    cout<<ans;
}