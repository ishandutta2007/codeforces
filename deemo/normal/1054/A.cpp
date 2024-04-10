#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int ans = abs(x-y)*t1;
	int ans2 = abs(x-z)*t2 + abs(x-y)*t2 + 3*t3;
	if (ans2 <= ans)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}