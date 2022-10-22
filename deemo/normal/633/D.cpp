#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 10;

int n, vec[MAXN], sz, cnt;
multiset<int>	st;
int sec[MAXN];
map<pair<int, int>, bool>	checked;

int solve(int a, int b){
	if (a == 0 && b == 0)
		return	cnt;
	if (checked[{a, b}])	return	1;
	checked[{a, b}] = 1;
	sz = 0;
	sec[sz++] = a;	st.erase(st.find(a));
	sec[sz++] = b;	st.erase(st.find(b));
	int c;
	while (1){
		c = b + a;
		if (st.find(c) == st.end())	break;
		st.erase(st.find(c));
		sec[sz++] = c;
		a = b;
		b = c;
	}

	for (int i = 0; i < sz; i++)
		st.insert(sec[i]);
	return	sz;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		if (vec[i] == 0)	cnt++;
		st.insert(vec[i]);
	}	
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				ans = max(ans, solve(vec[i], vec[j]));
	cout << ans << "\n";
	return	0;
}