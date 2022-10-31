#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

map<int, int> events;
const int N = 1e5+5;
int heights[N];
int n,m;

int fw[N];
int bw[N];

vector<int> lis_inc(int* arr) {
	vector<int> vals = {heights[0]};
	arr[0] = 1;
	for(int i = 1; i < m; ++i) {
		if(heights[i] >= vals.back()) {
			vals.push_back(heights[i]);
			arr[i] = vals.size();
		} else {
			int lo = -1, hi = vals.size()-1;
			while(hi-lo-1) {
				int md = (lo+hi)/2;
				if(heights[i] >= vals[md])
					lo = md;
				else hi = md;
			}
			vals[hi] = heights[i];
			arr[i] = hi+1;
		}
	}
	return vals;
}

int main() {	
	fio;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		++heights[l-1];
		--heights[r];
	}
	for(int i = 1; i < m; ++i)
		heights[i] += heights[i-1];

	lis_inc(fw);

	reverse(heights, heights + m);
	lis_inc(bw);
	reverse(bw, bw + m);

	int best = 0;
	for(int i = 0; i < m; ++i) {
		best = max(best, fw[i] + bw[i] - 1);
	}
	cout << best << "\n";

}