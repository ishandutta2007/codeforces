#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

const int MAXN = 300 + 4;

int n;
char c[MAXN][MAXN];
set<char>	st, ss;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			cin >> c[i][j];
			if (i == j || i + 1 == n - j)	st.insert(c[i][j]);
			else	ss.insert(c[i][j]);
		}
	if (st.size() == 1 && ss.size() == 1 && *ss.begin() != *st.begin())
		cout << "YES\n";
	else
		cout << "NO\n";
	return	0;
}