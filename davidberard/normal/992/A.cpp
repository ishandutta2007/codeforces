#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	set<int> st;
	cin >> N;
	for(int i=0;i<N;++i) {
		int a;
		cin >> a;
		if(a != 0)
			st.insert(a);
	}
	cout << st.size() << endl;

	return 0;
}