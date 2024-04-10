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

int a[200005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int mx = 0, mxi;
	for(int i=0;i<n;i++)
		if(a[i] > mx) {
			mx = a[i];
			mxi = i;
		}
	vi v;
	v.PB(mx);
	for(int l=mxi-1, r=mxi+1;l>=0||r<n;) {
		if(l >= 0 && (r >= n || a[l] > a[r]))
			v.PB(a[l--]);
		else
			v.PB(a[r++]);
	}
	for(int i=0;i<v.size()-1;i++)
		if(v[i] <= v[i+1]) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
}