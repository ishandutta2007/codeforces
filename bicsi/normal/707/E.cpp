/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

struct Str {
	int a, b, w;
	Str(int a, int b, int w):
		a(a), b(b), w(w) {}
};

const int kMaxN = 2005;

long long T[kMaxN];
bool Need[kMaxN][kMaxN];
long long Ans[kMaxN];
int A[kMaxN], B[kMaxN], C[kMaxN], D[kMaxN];
vector<Str> Pos[kMaxN];
int asks;
bool Avail[kMaxN];
vector<int> Queries[kMaxN];

int n, m, k;

void add(int c, int val) {
	//cerr << "Adding " << val << " on " << l << " " << c << '\n';	
	for(int j = c; j <= m; j += (j & -j))
		T[j] += val;
}

long long query(int c) {
	//cerr << "querying " << l << " " << c << '\n';
	long long s = 0;
	for(int j = c; j > 0; j -= (j & -j))
		s += T[j];
	//cerr << "got " << s << '\n';
	return s;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= k; ++i) {
		int a, b, w, c;
		
		scanf("%d", &c);
		Pos[i].reserve(c);
		while(c--) {
			scanf("%d%d%d", &a, &b, &w);
			Pos[i].emplace_back(a, b, w);
		}
	}

	for(int i = 1; i <= k; ++i)
		Avail[i] = 1;

	int q;
	scanf("%d", &q);
	char str[20];
	while(q--) {
		scanf("%s", str);
		if(strcmp(str, "SWITCH") == 0) {
			int x;
			scanf("%d", &x);
			Avail[x] ^= 1;
		} else {
			assert(strcmp(str, "ASK") == 0);

			++asks;
			scanf("%d%d%d%d", A+asks, B+asks, C+asks, D+asks);

			Queries[A[asks] - 1].push_back(asks);
			Queries[C[asks]].push_back(asks);

			for(int i = 1; i <= k; ++i)
				Need[asks][i] = Avail[i];
		}
	}

	for(int i = 1; i <= k; ++i) {
		auto &V = Pos[i];
		//cerr << "At #" << i << '\n';
		sort(V.begin(), V.end(), [](Str a, Str b) {
			return a.a < b.a;
		});

		int cur_i = 0;
		for(int l = 0; l <= n; ++l) {
			while(cur_i < V.size() && V[cur_i].a <= l) {
				add(V[cur_i].b, V[cur_i].w);
				++cur_i;
			}

			for(auto qi : Queries[l]) {
				if(!Need[qi][i]) continue;
				
				if(l == C[qi]) {
					Ans[qi] += query(D[qi]);
					Ans[qi] -= query(B[qi] - 1);
				} else {
					Ans[qi] -= query(D[qi]);
					Ans[qi] += query(B[qi] - 1);
				}
			}
		}
	}

	for(int i = 1; i <= asks; ++i)
		printf("%I64d\n", Ans[i]);



	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/