#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
 
const int N=3e5+5;

int n, m;

int arr[N];
map<int, int>cn;
vector<vector<int>>vec;

map<pair<int, int>, bool>che;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		
		cin>>n>>m;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			cn[arr[i]]++;
		}
		vec.clear();
		vec.resize(n+1);
		set<int>pa;
		for(auto u:cn){
			vec[u.second].pb(u.first);
			pa.insert(u.second);
			che[{u.first, u.first}]=1;
		}
		vector<int>st;
		for(auto u:pa){
			st.pb(u);
		}
		long long int ans=0;
		
		for(int i=0; i<m; i++){
			int x, y;
			cin>>x>>y;
			che[{x, y}]=1;
			che[{y, x}]=1;
		}
		
		for(auto u1:st){
			for(auto u2:st){
				int pt1=vec[u1].size()-1;
				int pt2=vec[u2].size()-1;
				priority_queue<pair<int, pair<int, int>>>pq;
				map<pair<int, int>, bool>don;
				pq.push({vec[u1][pt1]+vec[u2][pt2], {pt1, pt2}});
				while(!pq.empty()){
					auto u=pq.top();
					pq.pop();
					if(don[{u.s.f, u.s.s}]){
						continue;
					}
					don[{u.s.f, u.s.s}]=1;
					if(!che[{vec[u1][u.s.f], vec[u2][u.s.s]}]){
						long long int tot1=u1+u2;
						long long int tot2=u.f;
						ans=max(ans, tot1*tot2);
						break;
					}
					if(u.s.f>0){
						pq.push({vec[u1][u.s.f-1]+vec[u2][u.s.s], {u.s.f-1, u.s.s}});
					}
					if(u.s.s>0){
						pq.push({vec[u1][u.s.f]+vec[u2][u.s.s-1], {u.s.f, u.s.s-1}});
					}
				}
			}
		}
		
		cn.clear();
		che.clear();
		cout<<ans<<endl;
	}
	
	return 0;
}