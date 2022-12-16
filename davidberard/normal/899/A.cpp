#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N;

	cin >> N;
	int two=0, one=0;
	int v;
	for(int i=0;i<N;++i) {
		cin >> v;
		two += (v == 2);
		one += (v == 1);
	}
	int d = min(two, one);
	two -= d;
	one -= d;
	int e = one/3;
	cout << d+e << endl;
	
	

	return 0;
}