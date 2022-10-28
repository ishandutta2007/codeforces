#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int
const int N=320;
bool comp(pair<pair<int, int>, int>a, pair<pair<int, int>, int>b){
	return (make_pair(a.f.f/N, a.f.s)<make_pair(b.f.f/N, b.f.s));
}
int cnt[500000];
main() {
	int n, k;
	cin>>n>>k;
	int t[n];
	for(int i=0; i<n; i++){
		cin>>t[i];
	}
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		if(t[i]==2){
			arr[i]=-arr[i];
		}
	}
	int pre[n+1];
	pre[0]=0;
	for(int i=1; i<=n; i++){
		pre[i]=pre[i-1]+arr[i-1];
	}
	set<int>s;
	for(int i=0; i<=n; i++){
		s.insert(pre[i]);
		s.insert(pre[i]+k);
		s.insert(pre[i]-k);
	}
	map<int, int>m;
	int i=0;
	for(auto it=s.begin(); it!=s.end(); it++){
		m[(*it)]=i;
		i++;
	}
	int pc[n+1];
	int lc[n+1];
	int rc[n+1];
	for(int i=0; i<=n; i++){
		pc[i]=m[pre[i]];
		lc[i]=m[pre[i]-k];
		rc[i]=m[pre[i]+k];
	}
	
	int q;
	cin>>q;
	vector<pair<pair<int, int>, int>>query;
	for(int i=0; i<q; i++){
		int l, r;
		cin>>l>>r;
		query.push_back({{l, r}, i});
	}
	sort(query.begin(), query.end(), comp);
	int cur_l=0;
	int cur_r=-1;
	int ans=0;
	int rep[q];
	for(int i=0; i<q; i++){
		int l=query[i].f.f;
		l--;
		int r=query[i].f.s;
		while(cur_l>l){
			cur_l--;
			ans+=cnt[rc[cur_l]];
			cnt[pc[cur_l]]++;
			
		}
		while(cur_r<r){
			cur_r++;
			ans+=cnt[lc[cur_r]];
			cnt[pc[cur_r]]++;
		}
		
		while(cur_l<l){
			cnt[pc[cur_l]]--;
			ans-=cnt[rc[cur_l]];
			
			cur_l++;
		}
		while(cur_r>r){
			cnt[pc[cur_r]]--;
			ans-=cnt[lc[cur_r]];
			
			cur_r--;
		}
		rep[query[i].s]=ans;
		
	}
	for(int i=0; i<q; i++){
		cout<<rep[i]<<endl;
	}
	return 0;
}