#include <bits/stdc++.h>

using namespace std;

int sol(vector<int> &v, int a, int b, int r) {
	vector<int> n;
	for(int i=0;i<v.size();i+=2) {
		if((v[i] == a && v[i+1] == b) || (v[i] == b && v[i+1] == a))
			return r;
		if(v[i] == a || v[i+1] == a) n.push_back(a);
		else if(v[i] == b || v[i+1] == b) n.push_back(b);
		else n.push_back(v[i]);
	}
	return sol(n, a, b, r+1);
}

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v(n);
	for(int i=0;i<n;i++) v[i] = i + 1;
	int ans = sol(v, a, b, 1);
	if(pow(2, ans) == n) cout << "Final!" << endl;
	else cout << ans << endl;
}