//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int INF = 1e9;

int n,t,mint = INF,ans;
int s[MAXN],d[MAXN]; 

int main () {
	cin >> n >> t;
	for(int i = 1;i <= n; ++i) {
		cin >> s[i] >> d[i];
		int tmp = s[i];
		while(tmp < t) tmp += d[i];
		if(tmp - t < mint) {
			mint = tmp - t;
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}