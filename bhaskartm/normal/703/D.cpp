#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1000;
int n;
int m;
int arr[1000001];
int xo[1000001];
int out[1000001];
int mat[1000001];
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	int ga=a.f.f/N;
	int gb=b.f.f/N;
	if(ga==gb){
		return (ga & 1) ? a.f.s <b.f.s : a.f.s > b.f.s;
	}
	else{
		return a.f.f<b.f.f;
	}
    
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;

	unordered_map<int, int>ma;
	set<int>se;
	
	
	for(int i=0; i<n; i++){
		cin>>arr[i];
		xo[i]=arr[i];
		se.insert(arr[i]);
	}
	
	int pt=0;
	for(auto it=se.begin(); it!=se.end(); it++){
		ma[(*it)]=pt;
		pt++;
	}
	for(int i=0; i<n; i++){
		arr[i]=ma[arr[i]];
	}
	
	
	
	cin>>m;
	vector<pair<pair<int, int>, int>>q;
	for(int i=0; i<m; i++){
		int l, r;
		cin>>l>>r;
		l--;
		r--;
		q.pb({{l, r}, i});
	}
	sort(q.begin(), q.end(), comp);
	int cur_l=0;
	int cur_r=-1;
	
	int ans=0;
	
	for(int i=0; i<n; i++){
		mat[i]=0;
	}
	for(int i=0; i<m; i++){
		int l=q[i].f.f;
		int r=q[i].f.s;
		
		while(cur_l>l){
			cur_l--;
			if(mat[arr[cur_l]]==0){
				mat[arr[cur_l]]++;
			}
			else{
				mat[arr[cur_l]]++;
				ans=ans^(xo[cur_l]);
			}
		}
		while(cur_r<r){
			
			cur_r++;
			if(mat[arr[cur_r]]==0){
				mat[arr[cur_r]]++;
			}
			else{
				mat[arr[cur_r]]++;
				ans=ans^(xo[cur_r]);
			}
		}
		while(cur_l<l){
			if(mat[arr[cur_l]]==1){
				mat[arr[cur_l]]--;
			}
			else{
				mat[arr[cur_l]]--;
				ans=ans^(xo[cur_l]);
			}
			cur_l++;
		}
		while(cur_r>r){
			if(mat[arr[cur_r]]==1){
				mat[arr[cur_r]]--;
			}
			else{
				mat[arr[cur_r]]--;
				ans=ans^(xo[cur_r]);
			}
			cur_r--;
		}
		out[q[i].s]=ans;
	}
	for(int i=0; i<m; i++){
		cout<<out[i]<<endl;
	}
	return 0;
}