#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=50005;
const int M=100005;
const int INF=1e9;
int l[M];
int r[M];
int n, m;
vector<vector<int>>vecs;
int tot=0;
int len;
set<pair<int, int>>t[4*N+5];


void update(int v, int tl, int tr, int l1, int r1, int ind){
	if(t[v].empty()){
		t[v].insert({r1, ind});
	}
	else{
		auto it=t[v].upper_bound({r1, INF});
		
		if(it==t[v].begin()){
			
			t[v].insert({r1, ind});
			vector<pair<int, int>>rem;
			
			for(it=t[v].begin(); it!=t[v].end(); it++){
				if((*it).s>ind){
					rem.pb(*it);
				}
				else if((*it).s<ind){
					break;
				}
			}
			for(auto u:rem){
				t[v].erase(u);
			}
		}
		else{
			it--;
			if(((*it).s)>ind){
				t[v].insert({r1, ind});
				vector<pair<int, int>>rem;
				for(auto it=t[v].find({r1, ind}); it!=t[v].end(); it++){
					if((*it).s>ind){
						rem.pb(*it);
					}
					else if((*it).s<ind){
						break;
					}
				}
				for(auto u:rem){
					t[v].erase(u);
				}
			}
		}
	}
	if(tl!=tr){
		int tm=(tl+tr)/2;
		if(l1<=tm){
			update(2*v, tl, tm, l1, r1, ind);
		}
		else{
			update(2*v+1, tm+1, tr, l1, r1, ind);
		}
	}
}

int mini(int v, int tl, int tr, int l1, int l2, int r1){
	if(l1>l2){
		return INF;
	}
	if(l1==tl && l2==tr){
		auto it=t[v].upper_bound({r1, INF});
		if(it==t[v].begin()){
			return INF;
		}
		else{
			it--;
			return (*it).s;
		}
	}
	int tm=(tl+tr)/2;
	
	return min(mini(2*v, tl, tm, l1, min(l2, tm), r1), mini(2*v+1, tm+1, tr, max(l1, tm+1), l2, r1));
}


void fu(int l1, int r1){
	if(r1-l1+1<len){
		
		return;
	}
	int id=mini(1, 0, n-1, l1, n-1, r1);
	
	if(id<m){
		tot+=(r[id]-l[id]+1);
		fu(l1, l[id]-1);
		fu(r[id]+1, r1);
	}
} 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	vecs.resize(n+5);
	
	for(int i=0; i<m; i++){
		cin>>l[i]>>r[i];
		l[i]--;
		r[i]--;
		vecs[r[i]-l[i]+1].pb(i);
	}
	
	vector<int>fin;
	for(int i=n; i>=1; i--){
		len=i;
		tot=0;
		for(auto u:vecs[i]){
			update(1, 0, n-1, l[u], r[u], u);
			
		}
		
		fu(0, n-1);
		fin.pb(tot);
	}
	reverse(fin.begin(), fin.end());
	for(auto u:fin){
		cout<<u<<endl;
	}
	
	return 0;
}