#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ook order_of_key
#define fbo find_by_order

using namespace std;

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
class Obj{
public:
	int big, small;
	int cnt;
	Obj(int a, int b){
		big = a;
		small = b;
		cnt = 0;
	}
	bool operator<(const Obj &o) const{
		return cnt<o.cnt;
	}
};
bool lesss(int a, int b){
	cout << "? " << (a+1) << " " << (b+1) << endl;
	string s;
	cin >> s;
	return s=="<";
}
int main() {
	int cases;
	cin >> cases;
	for(int q=1; q<=cases; q++){
		int n;
		cin >> n;
		n *= 2;
		vector<Obj> all;
		for(int i = 1; i<=n; i+=2){
			int big = i-1;
			int small = i;
			if(lesss(big,small)){
				swap(big,small);
			}
			all.pb(Obj(big,small));
		}
		for(int i = 0; i<all.size(); i++){
			for(int j = i+1; j<all.size(); j++){
				if(lesss(all[i].small,all[j].small)){
					all[j].cnt++;
				}
				else{
					all[i].cnt++;
				}
			}
		}
		sort(all.begin(),all.end());
		reverse(all.begin(),all.end());
		vector<pair<int, int> > right;
		for(int i = 1; i<all.size(); i++){
			right.pb(mp(0,all[i].small));
			right.pb(mp(0,all[i].big));
		}
		for(int i = 0; i<right.size(); i++){
			for(int j = i+1; j<right.size(); j++){
				if(lesss(right[i].second,right[j].second)){
					right[j].first++;
				}
				else{
					right[i].first++;
				}
			}
		}
		sort(right.begin(),right.end());
		reverse(right.begin(),right.end());
		lesss(all[0].small,right[n/2-2].second);
		cout << "!" << endl;
	}
	return 0;
}