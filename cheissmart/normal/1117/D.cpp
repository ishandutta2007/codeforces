#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> Mat;

const int INF = 1e9 + 7;

Mat mul(Mat m1, Mat m2) {
	Mat res(m1.size(), vi(m2[0].size()));
	for(int i=0;i<m1.size();i++) {
		for(int j=0;j<m2[0].size();j++) {
			for(int k=0;k<m1[0].size();k++) {
				res[i][j] += m1[i][k]*m2[k][j];
				res[i][j] %= 1000000007;
			}
		}
	}
	return res;
}

Mat pw(Mat m, int n) {
	if(n == 0) {
		Mat res(m.size(), vi(m.size()));
		for(int i=0;i<m.size();i++)
			res[i][i] = 1;
		return res;
	}
	Mat t = pw(m, n/2);
	if(n % 2) {
		return mul(mul(t, t), m);
	} else {
		return mul(t, t);
	}
}

int32_t main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	if(n < m) {
		cout << 1 << endl;
		return 0;
	}
	Mat M(m, vi(m)), V(m, vi(1));
	for(int i=0;i<m-1;i++){
		M[i][i+1] = 1;
	}
	M[m-1][0] = M[m-1][m-1] = 1;
	for(int i=0;i<m;i++)
		V[i][0] = 1;
	cout << mul(pw(M, n-m+1), V)[m-1][0] << endl;
}