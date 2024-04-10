#include <bits/stdc++.h>
#define minus djsf
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int sum(int x){
	return x*(x-1)/2;
}

int S(int l, int r){
	int Q = sum(r-l+1);
	return Q+(r-l+1)*l;
}

int get_pos(int block, int k) {
	if (block == 1) return S(1, k) - 1;

	int where = (block - 1) / k + 1, pos = (block-1) % k;
	int L = (k*k+1)*(where - 1) + k*pos + 1, R = (k*k+1)*(where - 1) + k*(pos+1);

	int T = get_pos(where, k) + (k*k+1)*(where - 1) + 1;

	//cout << "==== " << L << " " << R << " " << T << endl;

	int sum = S(L, R);
	if (T < L) {
		sum -= L;
		sum += (R+1);
	}
	else if (T <= R){
		sum -= T;
		sum += (R+1);
	}


	return sum - ((block-1)*(k*k+1) + 1);


}

void solve() {
	int n, k;
	cin >> n >> k;

	int block = (n-1) / (k*k+1) + 1, pos = (n-1) % (k*k+1);

	int spec = get_pos(block, k);


	//cout << "==== " << block << " " << pos << " " << spec << endl;
	
	if (spec == pos) {
		cout << block * (k+1) << "\n";
		return;
	}
	int gp = k*k*(block - 1) + pos - (pos > spec);

	cout << gp + gp/k + 1 << "\n";

}
 
signed main()
{
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("P_output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i=0; i < t; ++i) solve();
	
}