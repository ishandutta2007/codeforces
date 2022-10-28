#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int n, m, k; // m is small
const int N=1e6+5;
const int M=5e5+5;
int ind1[N];
int ind2[N];
int cnt[M];
bool don[M];
vector<int>posi;
int ans;

 main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	vector<int>a;
	vector<int>b;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		a.pb(x);
	}
	for(int i=0; i<m; i++){
		int x;
		cin>>x;
		b.pb(x);
	}
	if(n<m){
		swap(a, b);
	}
	n=a.size();
	m=b.size();
	for(int i=0; i<N; i++){
		ind1[i]=-1;
		ind2[i]=-1;
	}
	for(int i=0; i<n; i++){
		ind1[a[i]]=i;
	}
	for(int i=0; i<m; i++){
		ind2[b[i]]=i;
	}
	
	
	
	
	
	for(int i=0; i<m; i++){
		int pos=ind1[b[i]];
		if(pos==-1){
			continue;
		}
		if(pos<i){
			cnt[n-(i-pos)]++;
		}
		else{
			cnt[pos-i]++;
		}
	}
	
	vector<int>c;
	for(auto u:a){
		c.pb(u);
	}
	for(auto u:a){
		c.pb(u);
	}
	int of=0;
	int val=0;
	
	while(1){
		if(don[of]){
			break;
		}
		val+=(m-cnt[of]);
		posi.pb(of);
		don[of]=1;
		of=(of+(m))%n;
	}
	
	int ti=k/val;
	
	ans=ti*m*(posi.size());
	k=k%val;
	if(k==0){
		ans=(ti-1)*m*(posi.size());
		k=val;
	}
	for(auto u:posi){
		if(k>(m-cnt[u])){
			ans+=(m);
			k-=(m-cnt[u]);
		}
		else{
			for(int i=0; i<m; i++){
				if(k==0){
					cout<<ans;
					return 0;
				}
				if(c[i+u]==b[i]){
					ans++;
				}
				else{
					ans++;
					k--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}