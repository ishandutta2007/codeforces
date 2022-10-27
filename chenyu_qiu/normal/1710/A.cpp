#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define int long long
 
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int a[k];
	int b[k];
	int c[k];
	for(int i=0; i< k; i++){
		cin >> a[i];
		b[i]=a[i];
		c[i]=a[i];
	}
	if(n==3 && m==3){
		for(int i=0; i< k; i++){
			if(a[i]>=9){
				yes; return;
			}
		}
		no;
		return;
	}
	else{
		for(int i=0; i< k; i++){
			b[i]/=m;
			c[i]/=n;
		}
		int sumn=0;
		int summ=0;
		bool all21=true;
		bool all22=true;
		for(int i=0; i< k; i++){
			if(b[i]<2)b[i]=0;
			if(c[i]<2)c[i]=0;
		}
		for(int i=0; i< k; i++){
			if(b[i]!=0 && b[i]!=2)all21=false;
			if(c[i]!=0 && c[i]!=2)all22=false;
			sumn+=b[i];
			summ+=c[i];
		}
		if(n%2==1 && all21)sumn=0;
		if(m%2==1 && all22)summ=0;
		if(sumn>=n || summ>=m){
			yes;
		}
		else no;
		}
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
	
}