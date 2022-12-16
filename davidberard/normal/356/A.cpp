#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

/**
 * 356A Knight Tournament
 * 
 * uf soltn
 */
vector<int> par;
void SETUP(int n) { par = vector<int>(n+1, -1); }
int FIND(int a) { return ((par[a]==-1?a:(par[a]=FIND(par[a]))));}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	SETUP(N);
	vector<int> ans(N, 0);
	for(int i=0;i<M;++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		//cerr << a << " " << b << " " << c << endl;
		while((a=FIND(a)) <= b) {
			if(a!=c-1) { 
				ans[a] = c, par[a]=a+1;
				//cerr << a << "-> " << ans[a] << endl;
			}
			++a;
		}
	}
	for(int i=0;i<N;++i) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}