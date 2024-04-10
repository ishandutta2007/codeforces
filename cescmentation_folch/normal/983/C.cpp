#include<bits/stdc++.h>

using namespace std;

const int N = 2010;
const int L = (750);
const int S = 10;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

struct pos {
	int s,l,n;
	int val;
	pos(int a,int b, int c, int v) : s(a),l(b),n(c),val(v) {}
	pos() {}
};

inline bool operator<(pos a,pos b) {
	return a.val > b.val;
}

ll D[S][L][N];

int calc(int a, int b, int c, int d) {
	int K[4] = {a,b,c,d};
	sort(K,K + 4);
	int res = K[3] + 10*K[2] + 100*K[1] + 1000*K[0];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vpi V(n);
	for (int i = 0; i < n; ++i) cin >> V[i].first >> V[i].second;
	memset(D,-1,sizeof(D));

	map<int,int> M;
	vector<int> G;
	for (int i = 0; i <= 9; ++i) 
		for (int j = 0; j <= 9; ++j)
			for (int w = 0; w <= 9; ++w)
				for (int t = 0; t <= 9; ++t) {
					int k= calc(i,j,w,t);
					if (M.count(k)==0) { 
						M[k] = G.size();
					        G.push_back(k);
					}
				}
	//cerr << G.size() << endl;
					


	D[1][0][0]= 0;
	priority_queue<pos> Q;
	Q.push(pos(1,0,0,0));
	while (!Q.empty()) {
		int pis = Q.top().s;
		int mask = Q.top().l;
		int seg = Q.top().n;
		int val = Q.top().val;
		//cerr << pis << ' ' << mask << ' ' << seg << ' '<< val << endl;
		Q.pop();
		if (seg == n and mask == 0) break;
		if (D[pis][mask][seg] < val) continue;
		int K[4];
		int j = 4;
		int antmask = G[mask];
		while (j--) {
			K[j] = antmask%10;
			antmask /= 10;
		}
		int sum = 0;
		int antseg = seg;
		for (int i = 0; i < 4; ++i) {
			if (pis == K[i]) {
			       ++sum;
			       K[i] = 0;
			} if (K[i] == 0 and seg < n and V[seg].first == pis) {
				++sum;
				K[i] = V[seg].second;
				++seg;
			}
		}
		int mask2 = M[calc(K[0],K[1],K[2],K[3])];
	//	for (int i = max(1,pis-1); i <= min(pis+1,9); ++i) {
		for (int i = 1; i <= 9; ++i) {
			int kk = D[pis][mask][antseg] + sum + abs(pis-i);
			if (D[i][mask2][seg] == -1 or D[i][mask2][seg] > kk) {
				D[i][mask2][seg] = kk;
		//		if (kk == -1) {
		//			cerr << D[pis][mask][antseg] << endl;
		//			cerr << pis << ' ' << mask << ' '<< antseg << ' ' << val << endl;
		//			cerr << i << ' ' << mask2 << ' ' << seg << ' ' << kk << endl;
		//			return 0;
		//		}
				Q.push(pos(i,mask2,seg, kk));
			}
		}
	}
	ll res = n*9*9;
	for (int i = 1; i < 10; ++i) 
		if (D[i][0][n] != -1)
			res = min(res, D[i][0][n]);
	cout << res << '\n';
}