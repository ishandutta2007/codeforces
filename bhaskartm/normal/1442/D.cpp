#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=3005;
vector<vector<int>>a;
int n, k;
vector<int>fin;
int ans=0;

void fu2(int i){
	int sz=a[i].size();
	sz--;
	for(int j=k-sz; j>=0; j--){
		fin[j+sz]=max(fin[j+sz], fin[j]+a[i][sz]);
	}
}


void fu(int l, int r){
	if(l==r){
		int sz=a[l].size();
		for(int i=0; i<=min(k, sz-1); i++){
			ans=max(ans, a[l][i]+fin[k-i]);
		}
		return;
	}
	int mid=(l+r)/2;
	vector<int>fin2=fin;
	for(int i=mid+1; i<=r; i++){
		fu2(i);
	}
	fu(l, mid);
	fin=fin2;
	for(int i=l; i<=mid; i++){
		fu2(i);
	}
	fu(mid+1, r);
}
 
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>k;
	
	a.resize(n);
	fin.resize(k+1);
	
	for(int i=0; i<=k; i++){
		fin[i]=0;
	}
	
	for(int i=0; i<n; i++){
		int sz;
		cin>>sz;
		a[i].resize(sz+1);
		a[i][0]=0;
		for(int j=1; j<=sz; j++){
			cin>>a[i][j];
			a[i][j]=a[i][j]+a[i][j-1];
		}
	}
	fu(0, n-1);
	cout<<ans<<endl;
	return 0;
}