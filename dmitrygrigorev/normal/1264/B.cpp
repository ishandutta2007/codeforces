#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> w(4);
	cin >> w[0] >> w[1] >> w[2] >> w[3];

	for (int start=0; start < 4; ++start) {
		bool tut = true;
		vector<int> v = w;
		vector<int> ans;
		int cur = start;
		int tot = v[0]+v[1]+v[2]+v[3];
		while (ans.size() < tot) {
			if (cur < 0 || cur > 3 || v[cur] == 0) {
				tut = false;
				break;
			}
			ans.push_back(cur);
			v[cur]--;
			if (cur != 0 && v[cur-1] > 0) cur--;
			else cur++;
		}
		if (!tut) continue;
		cout << "YES\n";
		for (int i=0;i<ans.size();++i) cout << ans[i] << " ";
		exit(0);
	}

	for (int start=0; start < 4; ++start) {
		bool tut = true;
		vector<int> v = w;
		vector<int> ans;
		int cur = start;
		int tot = v[0]+v[1]+v[2]+v[3];
		while (ans.size() < tot) {
			if (cur < 0 || cur > 3 || v[cur] == 0) {
				tut = false;
				break;
			}
			ans.push_back(cur);
			v[cur]--;
			if (cur != 3 && v[cur+1] > 0) cur++;
			else cur--;
		}
		if (!tut) continue;
		cout << "YES\n";
		for (int i=0;i<ans.size();++i) cout << ans[i] << " ";
		exit(0);
	}

	cout << "NO";

}