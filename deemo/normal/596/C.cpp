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

const int max_n = 4e5 + 100;
const int C = 1e5;

int n;
pair<int, int>	a[max_n];
int b[max_n];
pair<int, int>	save[max_n];
vector<pair<int, int>>	vec[max_n];
vector<int>	sec, gec[max_n];
int mp[max_n];

int main(){
	read_fast;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
		int t = a[i].second - a[i].first;
		vec[t + C].push_back({a[i].first, i});
		sec.push_back(t);
	}	
	sort(sec.begin(), sec.end());
	for (int i = 0; i < n; i++){
		cin >> b[i];
		gec[b[i] + C].push_back(i);
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		if (sec[i] != b[i]){
			cout << "NO" << endl;
			return 0;
		}

	for (int i = 0; i < max_n; i++){
		if (vec[i].empty())	continue;
		sort(vec[i].begin(), vec[i].end());
		for (int j = 0; j < gec[i].size(); j++)
			mp[vec[i][j].second] = gec[i][j];
	}

	for (int i = 0; i < n; i++){
		int g = mp[i] + 1;
		int f = (a[i].first + 1) * (a[i].second + 1);
		if (g < f){
			cout << "NO" << endl;
			return 0;
		}
		save[g - 1] = a[i];
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << save[i].first << " " << save[i].second << endl;
    return 0;
}