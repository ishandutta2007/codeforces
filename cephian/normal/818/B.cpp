#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 105;
int p[N],n,m;
set<int> used;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	fill(p,p+n,-1);
	int lst = -1;
	for(int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		--k;
		if(lst != -1) {
			int mv = ((k-lst)%n+n)%n;
			if(p[lst] == -1) {
				if(used.count(mv)) {
					cout << "-1\n";
					return 0;
				}
				p[lst] = mv;
				used.insert(mv);
			} else {
				if(p[lst] != mv) {
					cout << "-1\n";
					return 0;
				}
			}
		}
		lst = k;
	}
	int ctr = 1;
	for(int i = 0; i < n; ++i) {
		if(p[i] == -1) {
			while(used.count(ctr)) ++ctr;
			p[i] = ctr++;
		}
		if(p[i] == 0) p[i] = n;
		cout << p[i] << " ";
	}
	cout << "\n";
	
}