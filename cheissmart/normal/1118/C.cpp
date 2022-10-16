#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int m[1024], a[25][25];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n*n;i++) {
		int t;
		cin >> t;
		m[t]++;
	}
	if(n % 2 == 0) {
		vi v;
		for(int i=0;i<1024;i++)
			if(m[i] % 4) {
				cout << "NO" << endl;
				return 0;
			}
			else
				for(int j=0;j<m[i]/4;j++)
					v.PB(i);
		for(int i=0;i<n/2;i++)
			for(int j=0;j<n/2;j++) {
				a[i][j] = v.back();
				v.pop_back();
			}
		for(int i=0;i<n/2;i++)
			for(int j=n/2;j<n;j++)
				a[i][j] = a[i][n-j-1];
		for(int i=n/2;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j] = a[n-i-1][j];
		cout << "YES" << endl;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cout << a[i][j] << " \n"[j==n-1];
		return 0;
	}
	vector<pi> v;
	for(int i=1;i<1024;i++)
		if(m[i])
			v.EB(i, m[i]);
    int k = n / 2;
    vi vv, vvv, vvvv;
	for(int i=0;vv.size() < k*k && i<v.size();i++) {
		while(vv.size()<k*k && v[i].S >= 4) {
			v[i].S -= 4;
			vv.PB(v[i].F);
		}
	}
	if(vv.size() != k*k) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i=0;vvv.size() < 2*k && i<v.size();i++) {
		while(vvv.size()<2*k && v[i].S >= 2) {
			v[i].S -= 2;
			vvv.PB(v[i].F);
		}
	}
	if(vvv.size() != 2*k) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i=0;vvvv.size() < 1 && i<v.size();i++) {
		while(vvvv.size()<1 && v[i].S >= 1) {
			v[i].S -= 1;
			vvvv.PB(v[i].F);
		}
	}
	if(vvvv.size() != 1) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++) {
			a[i][j] = vv.back();
			vv.pop_back();
		}
	for(int i=0;i<k;i++) {
		a[k][i] = vvv.back();
		vvv.pop_back();
	}
	for(int i=0;i<k;i++) {
		a[i][k] = vvv.back();
		vvv.pop_back();
	}
	a[k][k] = vvvv[0];
	for(int i=0;i<=k;i++)
		for(int j=k;j<n;j++)
			a[i][j] = a[i][n-j-1];
	for(int i=k;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j] = a[n-i-1][j];
	
	cout << "YES" << endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cout << a[i][j] << " \n"[j==n-1];
}