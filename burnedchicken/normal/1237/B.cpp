#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(ll i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll n,Max,ans;
	cin >> n;
	ll a[n],b[n],ind[n],pos[n];
	loop(n){
		cin >> a[i];
		ind[a[i]-1]=i;
	}
	loop(n){
		cin >> b[i];
		b[i]=ind[b[i]-1];
		pos[b[i]]=i;
	}
	Max=-1;
	ans=0;
	loop(n){
		if(pos[i]<Max) ans++;
		else Max=pos[i];
	}
	cout << ans << endl;
	return 0;
}