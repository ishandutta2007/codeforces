#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 1e9 + 7, MM = 1e9 + 6;

struct Mat{
	int a[5][5];
	Mat() {
		memset(a, 0, sizeof a);
	}
	Mat operator * (const Mat B) const {
		Mat R;
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				for(int k=0;k<5;k++)
					R.a[i][j] = (R.a[i][j] + a[i][k] * B.a[k][j]) % MM;
		return R;
	}
};

Mat pw1(Mat A, int b) {
	if(b == 0) {
		Mat B;
		for(int i=0;i<5;i++)
			B.a[i][i] = 1;
		return B;
	}
	Mat B = pw1(A, b/2);
	if(b & 1) return B * B * A;
	else return B * B;
}

int pw2(int a, int b) {
	if(b == 0) return 1;
	int t = pw2(a, b/2);
	if(b & 1) return t * t % M * a % M;
	else return t * t % M;
}

int32_t main()
{
	IO_OP;
	
	Mat A, B, v1, v2, v3, v4;
	v1.a[0][0] = 1, v2.a[1][0] = 1, v3.a[2][0] = 1;
	A.a[0][1] = A.a[1][2] = A.a[2][0] = A.a[2][1] = A.a[2][2] = 1;
	v4.a[3][0] = v4.a[4][0] = 2;
	B.a[0][1] = B.a[1][2] = 1;
	for(int i=0;i<4;i++)
		B.a[2][i] = 1;
	B.a[3][3] = B.a[3][4] = B.a[4][4] = 1;
	int n, f1, f2, f3, c;
	cin >> n >> f1 >> f2 >> f3 >> c;
	A = pw1(A, n-1);
	B = pw1(B, n-1);
	v1 = A * v1, v2 = A * v2, v3 = A * v3, v4 = B * v4;
	int p1 = v1.a[0][0], p2 = v2.a[0][0], p3 = v3.a[0][0], p4 = v4.a[0][0];
	int ans = 1;
	ans = ans * pw2(f1, p1) % M;
	ans = ans * pw2(f2, p2) % M;
	ans = ans * pw2(f3, p3) % M;
	ans = ans * pw2(c, p4) % M;
	cout << ans << endl;	

}