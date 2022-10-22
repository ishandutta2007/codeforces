#include <bits/stdc++.h>

using namespace std;

const int N = 16384;
int a[N];

void solve() {
	for (int i = 0; i < N; i++)
		a[i] = i;
	random_shuffle(a, a + N);
	cout << "? ";
	for (int i = 0; i < 100; i++)
		cout << a[i] << ' ';
	cout << endl;
	int k;
	cin >> k;
	set <int> st;
	for (int i = 0; i < 100; i++) 
		st.insert(a[i] ^ k);
	set <int> st2;
	cout << "? ";
	for (int i = 100; i < 200; i++)
		cout << a[i] << ' ';
	cout << endl;
	cin >> k;
	for (int i = 100; i < 200; i++) 
		st2.insert(k ^ a[i]);
	vector <int> v;
	for (auto x : st2) {
		if (st.count(x)) {
			v.push_back(x);
		}
	}
	if (v.size() > 1) {
		while(true);
	}
	cout << "! " << v[0] << endl;
}

int main() {
	srand(time(NULL));
	solve();
}