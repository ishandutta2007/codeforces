#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

const int MAXN = 52 + 3;
const int MAX = MAXN * MAXN * MAXN * MAXN;

int n;
string vec[MAXN];
set<pair<pair<string, string>, pair<string, int>>>	st;

bool match(string a, string b){
	bool fl = 0;
	for (int i = 0; i < min((int)a.size(), (int)b.size()); i++)
		if (a[i] == b[i])	fl = 1;
	return	fl;
}

void dfs(string a, string b, string c, int x){
	if (st.count({{a, b}, {c, x}}))	
		return;
	st.insert({{a, b}, {c, x}});
	if (x == 0)	
		return;
	
	if (match(c, b))
		dfs(vec[x - 1], a, c, x - 1);
	if (match(c, vec[x - 1]))
		dfs(c, a, b, x - 1);
}

int main(){
	cin >> n;
	n += 3;
	vec[0] = vec[1] = vec[2] = "z";
	for (int i = 3; i < n; i++)	cin >> vec[i];
	dfs(vec[n - 3], vec[n - 2], vec[n - 1], n - 3);

	bool fl = 0;
	for (int i = 3; i < n; i++)
		if (st.count({{"z", "z"}, {vec[i], 1}}))	fl = 1;
	if (fl)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}