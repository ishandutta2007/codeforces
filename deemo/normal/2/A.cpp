#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

const int max_n = 1e6 + 10;

string a[max_n];
map<string, short>	seen;

int main(){
	read_fast;
	int n;	cin >> n;
	map<string, int>	mp;
	vector<string>	vec, sec;
	map<string, vector<pair<int, int>>>	save;

	int maxi;
	string ind;
	while(n--){
		string s;
		int val;
		cin >> s >> val;
		vec.pb(s);
		mp[s] += val;
		save[s].pb({mp[s], n + 1});
	}

	maxi = -1, ind = -1;
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++){
		string s = vec[i];
		if (seen[s])	continue;
		seen[s] = 1;

		if (mp[s] > maxi){
			maxi = mp[s];
			ind = s;
			cnt = 1; 
		}
		else if (mp[s] == maxi)	cnt++;
	}

	if (cnt == 1){
		cout << ind << endl;
		return 0;
	}

	map<string, bool>	mark;
	for (int i = 0; i < vec.size(); i++){
		string s = vec[i];
		if (seen[s] == 2)	continue;
		seen[s] = 2;

		if (mp[s] == maxi)
			sec.pb(s);
	}
	
	map<string, int>	m;
	for (int i = 0; i < sec.size(); i++){
		string s = sec[i];
		for (int j = 0; j < save[s].size(); j++){
			pair<int, int>	t = save[s][j];
			if (t.first >= maxi)
				m[s] = max(m[s], t.second);
		}
	}

	maxi = -1;
	for (int i = 0; i < sec.size(); i++){
		string s = sec[i];
		if (m[s] > maxi){
			maxi = m[s];
			ind = s;
		}
	}
	cout << ind << endl;
	return 0;
}