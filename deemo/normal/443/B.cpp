#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 200 + 4;

string s;
int k, ans, n;

int main(){
	cin >> s >> k;
	n = s.size();
	for (int i = 1; i <= k; i++)
		ans = max(ans, min(i + n - 1, k - i + 1) * 2);

	for (int i = 1; i < n; i++){
		int tl = i - 1, tr = i, sz = 1;
		while (tl >= 0 && tr < n + k){
			bool fl = 1;
			for (int j = tl; j < tl + sz; j++)
				if (j + sz < n && s[j] != s[j + sz])	fl = 0;
			if (fl)
				ans = max(ans, tr - tl + 1);
			tl--;
			tr++;
			sz++;
		}
	}
	cout << ans << endl;
	return	0;
}