#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int n, m, k;
int cnt[2005];

void fa(int x){
	if(x>=0 && x<2005){
		cnt[x]++;
	}
}

void fs(int x){
	if(x>=0 && x<2005){
		cnt[x]--;
	}
}



main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m>>k;
	vector<pair<int, int>>vec;
	for(int i=0; i<m; i++){
		int l, r;
		cin>>l>>r;
		vec.pb({l, r});
	}
	int maxi=0;
	for(int i=1; i<=n-k+1; i++){
		
		for(int j=0; j<=n; j++){
			cnt[j]=0;
		}
		int val=0;
		int it=0;
		for(auto u:vec){
			it++;
			int l=u.f;
			int r=u.s;
			if(i>=l){
				val+=max(0LL, min(r-i+1, k));
				continue;
			}
			else if(l>=i && r<=i+k-1){
				val+=(r-l+1);
				continue;
			}
			else if(i+k-1<l || i>r){
				fa(l-k+1);
				fs(min(l, r-k+1)+1);
				fs(max(l+1, r-k+2));
				fa(r+2);
			}
			else if(i+k-1>=l && i<l){
				
				fa(i+1);
				fs(min(l, r-k+1)+1);
				fs(max(l+1, r-k+2));
				fa(l+r-i-k+2);
				val+=(i+k-l);
			
			}
			
		}
		maxi=max(maxi, val);
		
		for(int j=1; j<=n; j++){
			cnt[j]=cnt[j]+cnt[j-1];
		}
		for(int j=i+1; j<=n-k+1; j++){
			val+=cnt[j];
			maxi=max(maxi, val);
		}
		
	}
	cout<<maxi<<endl;
	return 0;
}