#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	int cnt = 0;
	for(int i=1;i<N;++i)
		if(N%i == 0) ++cnt;
	cout << cnt << endl;
	return 0;
}