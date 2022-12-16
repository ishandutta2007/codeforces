#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	int tsum = 0;
	string s;
	cin >> s;
	vector<int> a(N);
	for(int i=0;i<N;++i)
	{
		int x = s[i]-'0';
		a[i] = x;
		tsum += x;
	}
	if(tsum == 0) {
		cout << "YES\n";
		return 0;
	}
	for(int i=1;i<tsum;++i)
	{
		if(tsum%i == 0)
		{
			int cval = 0;
			char good = true;
			//cerr << ".\n";
			for(int j=0;j<a.size();++j) {
				cval += a[j];
				//cerr << " cval " << cval << endl;
				if(cval == i)
				{
					cval = 0;
				} else if(cval > i)
				{
					good = false;
				}
			}
			if(good) {
				//cerr << " good for i = " << i << endl;
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}