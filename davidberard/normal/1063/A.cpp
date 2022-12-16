#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	string s;
	cin >> s;
	vector<int> amt(256, 0);
	for(auto& x : s)
	{
		amt[x]++;
	}
	vector<pii> ps;
	priority_queue<pii> pq;
	for(int i=0;i<amt.size();++i)
	{
		for(int j=0;j<amt[i];++j)
		{
			cout << (char) i;
		}
	}
	cout << endl;
	return 0;
}