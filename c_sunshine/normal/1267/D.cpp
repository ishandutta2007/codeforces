#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ook order_of_key
#define fbo find_by_order

using namespace std;

template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
	
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair

#define f first
#define s second
#define all(x) begin(x), end(x)
#define rsz resize

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

typedef string str;


typedef pair<ll,int> T;
	
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int deploy[n];
	int test[n];
	vector<bool> ct(n);
	for(int i =0; i<n; i++){
		int a, b, c;
		ct[i] = true;
		cin >> a >> b >> c;
		deploy[i] = 4*a+2*b+c;
	}
	for(int i = 0; i<n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		test[i] = 4*a+2*b+c;
	}
	int maxi = 7;
	vector<int> all[8][8];
	for(int i = 0; i<n; i++){
		all[deploy[i]][deploy[i]&test[i]].pb(i);
	}
	vector<int> li;
	li.pb(0);
	int from[8];
	for(int i = 0; i<8; i++){
		from[i] = -1;
	}
	for(int i =0 ; i<li.size(); i++){
		int now = li[i];
		int to = deploy[now] & test[now];
		if(from[to]!=-1){
			continue;
		}
		from[to] = now;
		for(int j = 0; j<8; j++){
			for(int k = 0; k<all[to][j].size(); k++){
				int dest = all[to][j][k];
				if(dest==0){
					continue;
				}
				li.pb(dest);
			}
		}
	}
	vector<int> cnt(8);
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			cnt[i] += all[i][j].size();
		}
	}
	bool ok = true;
	//011 = 3, 101 = 5, 110 = 6
	vector<pair<int, int> > ans;
	vector<bool> ign(8);
	if(cnt[3]>0 && from[3]==-1){
		int loc = 3;
		ign[loc] = true;
		int aval = 1;
		int bval = 2;
		int aind = -1;
		int bind = -1;
		for(int i = 0; i<8; i++){
			if(all[i][aval].size()>0){
				aind = all[i][aval][0];
			}
			if(all[i][bval].size()>0){
				bind = all[i][bval][0];
			}
		}
		if(aind==-1 || bind==-1){
			ok = false;
			cout << "Impossible" << endl;
			return 0;
		}
		int first = -1;
		for(int i = 0; i<8; i++){
			for(int j = 0; j<all[loc][i].size(); j++){
				int now = all[loc][i][j];
				ct[now] = false;
				if(first==-1){
					first=  now;
					ans.pb(mp(aind,now));
					ans.pb(mp(bind,now));
				}
				else{
					ans.pb(mp(first,now));
				}
			}
		}
	}
	
	
	
	if(cnt[5]>0 && from[5]==-1){
		int loc = 5;
		ign[loc] = true;
		int aval = 1;
		int bval = 4;
		int aind = -1;
		int bind = -1;
		for(int i = 0; i<8; i++){
			if(all[i][aval].size()>0){
				aind = all[i][aval][0];
			}
			if(all[i][bval].size()>0){
				bind = all[i][bval][0];
			}
		}
		if(aind==-1 || bind==-1){
			ok = false;
			cout << "Impossible" << endl;
			return 0;
		}
		int first = -1;
		for(int i = 0; i<8; i++){
			for(int j = 0; j<all[loc][i].size(); j++){
				int now = all[loc][i][j];
				ct[now] = false;
				if(first==-1){
					first=  now;
					ans.pb(mp(aind,now));
					ans.pb(mp(bind,now));
				}
				else{
					ans.pb(mp(first,now));
				}
			}
		}
	}
	
	
	
	if(cnt[6]>0 && from[6]==-1){
		int loc = 6;
		ign[loc] = true;
		int aval = 2;
		int bval = 4;
		int aind = -1;
		int bind = -1;
		for(int i = 0; i<8; i++){
			if(all[i][aval].size()>0){
				aind = all[i][aval][0];
			}
			if(all[i][bval].size()>0){
				bind = all[i][bval][0];
			}
		}
		if(aind==-1 || bind==-1){
			ok = false;
			cout << "Impossible" << endl;
			return 0;
		}
		int first = -1;
		for(int i = 0; i<8; i++){
			for(int j = 0; j<all[loc][i].size(); j++){
				int now = all[loc][i][j];
				ct[now] = false;
				if(first==-1){
					first=  now;
					ans.pb(mp(aind,now));
					ans.pb(mp(bind,now));
				}
				else{
					ans.pb(mp(first,now));
				}
			}
		}
	}
	for(int i = 1; i<8; i++){
		if(!ign[i] && cnt[i]>0 && from[i]==-1){
			ok = false;
			cout << "Impossible" << endl;
			return 0;
		}
		for(int j = 0; j<8 && !ign[i]; j++){
			for(int k = 0; k<all[i][j].size(); k++){
				if(all[i][j][k]==0){
					continue;
				}
				ans.pb(mp(from[i],all[i][j][k]));
			}
		}
	}
	cout << "Possible" << endl;
	cout << ct[0];
	for(int i = 1; i<n; i++){
		cout << " " << ct[i];
	}
	cout << endl;
	cout << ans.size() << endl;
	for(int i = 0; i<ans.size(); i++){
		cout << (ans[i].first+1) << " " << (ans[i].second+1) << endl;
	}
}