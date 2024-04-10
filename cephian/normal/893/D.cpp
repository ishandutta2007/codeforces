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

int n,d,b=0;
const int N = 1e5+5;
int a[N];
int hi[N];
const int NINF = -2e9;

int main() {	
	fio;
	cin >> n >> d;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	hi[n] = d;
	for(int i = n-1; i >= 0; --i) {
		if(a[i] == 0) {
			hi[i] = hi[i+1];
		} else {
			hi[i] = min(hi[i+1] - a[i],d);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] == 0) {
			if(b < 0) {
				++ans;
				b += max(0,hi[i] - b);
			}
		}
		b += a[i];
		if((a[i] == 0 && b < 0) || b > d) {
			cout << "-1\n";
			return 0;
		}
	}
	cout << ans << "\n";	
}