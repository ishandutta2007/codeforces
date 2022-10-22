#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

const int MAXN = 100 + 4;

int mp[300], n;
string vec[MAXN];
set<string>	st;

bool ok(int mask){
	st.clear();
	for (int i = 0; i < n; i++){
		int z = mp[vec[i][0]];
		string s = "??";
		if ((mask >> z) & 1)
			s[0] = vec[i][0];

		z = vec[i][1] - '0';
		if ((mask >> z) & 1)
			s[1] = vec[i][1];
		st.insert(s);
	}	
	return	(int)st.size() == n;
}

int main(){
	mp['R'] = 5;	mp['G'] = 6;	mp['B'] = 7;	mp['Y'] = 8;	mp['W'] = 9;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		vec[i][1]--;
	}
	sort(vec, vec + n);
	n = unique(vec, vec + n) - vec;

	int ans = 1e9;
	for (int i = 0; i < (1 << 10); i++)
		if (ok(i))
			ans = min(__builtin_popcount(i), ans);
	cout << ans << endl;
	return	0;
}