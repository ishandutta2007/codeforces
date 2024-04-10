#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int cnt[7];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int maxi=0;
	for(int i=0; i<n; i++){
		string st;
		cin>>st;
		for(int j=0; j<7; j++){
			if(st[j]=='1'){
				cnt[j]++;
				maxi=max(maxi, cnt[j]);
			}
		}
	}
	cout<<maxi;
	return 0;
}