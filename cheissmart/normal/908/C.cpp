#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int x[1024];
double y[1024];

int main()
{
	IO_OP;
	int n, r;
	cin >> n >> r;
	for(int i=0;i<n;i++) {
		cin >> x[i];
		y[i] = r;
		for(int j=0;j<i;j++) {
			if(4*r*r-(x[i]-x[j])*(x[i]-x[j]) >= 0) {
				y[i] = max(y[i], y[j] + sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j])));
			}
		}
		cout << fixed << setprecision(10) << y[i] << " ";
	}
	
}