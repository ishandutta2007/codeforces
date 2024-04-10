#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n,k,m,a,ans=0;
int v[100005];
int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n >> k;
	while(k--) {
		cin >> m;
		int len = 0;
		for(int i = 1; i <= m; ++i) {
			cin >> v[i];
			len += len==i-1 && v[i]==i;
		}
		if(len>0) ans += 2*(m-len);
		else ans += 2*m-1;
	}
	cout << ans << "\n";
	return 0;
}