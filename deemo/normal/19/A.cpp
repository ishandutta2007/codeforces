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

struct Team{
	int win, lose, ga, gs, draw;
};	

bool operator < (Team a, Team b){
	if (a.win * 3 + a.draw != b.win * 3 + b.draw)
		return	a.win * 3 + a.draw > b.win * 3 + b.draw;
	if (a.gs - a.ga != b.gs - b.ga)
		return	a.gs - a.ga > b.gs - b.ga;
	return	a.ga > b.ga;
}

bool cmp(pair<Team, string>	a, pair<Team, string>	b){
	return	a.first < b.first;
}

int main(){
	int n;	cin >> n;
	vector<string>	sec;
	map<string, Team>	mp;
	for (int i = 0; i < n; i++){
		string t;	cin >> t;	
		sec.pb(t);
	}

	for (int i = 0; i < n * (n - 1) / 2; i++){
		string s1;	cin >> s1;
		int j = 0;
		while (s1[j] != '-')	j++;
		string t1 = "", t2 = "";
		for (int w = 0; w < j; w++)
			t1 += s1[w];
		for (int w = j + 1; w < s1.size(); w++)
			t2 += s1[w];
		
		int x, y;
		scanf("%d:%d", &x, &y);

		if (y > x){
			swap(t1, t2);
			swap(x, y);
		}
		if (x > y){
			mp[t1].win += 1;
			mp[t1].gs += x;
			mp[t1].ga += y;
			mp[t2].lose += 1;
			mp[t2].gs += y;
			mp[t2].ga += x;
		}
		if (x == y){
			mp[t1].draw += 1;
			mp[t2].draw += 1;
			mp[t1].gs += x;
			mp[t1].ga += y;
			mp[t2].gs += y;
			mp[t2].ga += x;
		}
	}
	vector<pair<Team, string>>	vec;
	for (int i = 0; i < n; i++)
		vec.pb({mp[sec[i]], sec[i]});
	sort(vec.begin(), vec.end(), cmp);
	vector<string>	gec;
	for (int i = 0; i < n/2; i++)
		gec.push_back(vec[i].second);	
	sort(gec.begin(), gec.end());
	for (int i = 0; i < gec.size(); i++)
		cout << gec[i] << endl;
    return 0;
}