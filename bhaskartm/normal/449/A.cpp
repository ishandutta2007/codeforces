#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define s second
#define f first

main() {
	int n, m, k;
	cin>>n>>m>>k;
	if(k>n+m-2){
		cout<<-1;
		return 0;
	}
	vector<int>v;
	if(k<=n-1){
		v.pb(m*(n/(k+1)));
	}
	else{
		v.pb((m/(k-n+1+1)));
	}
	if(k<=m-1){
		v.pb(n*(m/(k+1)));
	}
	else{
		v.pb((n/(k-m+2)));
	}
	sort(v.begin(), v.end());
	cout<<v.back();
	return 0;
}