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

const int max_n = 200;

vector<pair<int, int>>	vec(3);
char c[max_n][max_n];
vector<char>	sec;

int main(){
	read_fast;
	ll area = 0;
	for (int i = 0; i < 3; i++){
		cin >> vec[i].first >> vec[i].second;
		area += vec[i].first * vec[i].second;
		sec.pb('A' + i);
	}
	
	int w = sqrt(area);
	if (w * w != area){
		cout << -1 << endl;
		return 0;
	}	

	bool fl = 0;
	for (int i = 0; i < 3; i++)
		if (vec[i].first > w || vec[i].second > w)	fl = 1;
	if (fl){
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < 3; i++)
		if (vec[i].first == w || vec[i].second == w)
			if (i != 0)	swap(vec[0], vec[i]), swap(sec[0], sec[i]);
	
	if (vec[0].first != w && vec[0].second != w){
		cout << -1 << endl;
		return 0;
	}		
	if (vec[0].first != w)	swap(vec[0].first, vec[0].second);

	for (int i = 0; i < vec[0].second; i++)
		for (int j = 0; j < w; j++)
			c[i][j] = sec[0];
	
	int y = w - vec[0].second;
	
	if (vec[1].second == y)	swap(vec[1].first, vec[1].second);
	if (vec[2].second == y)	swap(vec[2].first, vec[2].second);	

	fl = 0;
	if (vec[1].first == y && vec[2].first == y){
		for (int i = vec[0].second; i < w; i++)
			for (int j = 0; j < vec[1].second; j++)
				c[i][j] = sec[1];
		for (int i = vec[0].second; i < w; i++)
			for (int j = vec[1].second; j < w; j++)
				c[i][j] = sec[2];
		fl = 1;
	}		

	if (vec[1].second == w)	swap(vec[1].first, vec[1].second);
	if (vec[2].second == w)	swap(vec[2].first, vec[2].second);
	
	if (vec[1].first == w && vec[2].first == w){
		for (int i = vec[0].second; i < vec[0].second + vec[1].second; i++)
			for (int j = 0; j < w; j++)
				c[i][j] = sec[1];
		for (int i = vec[0].second + vec[1].second; i < w; i++)
			for (int j = 0; j < w; j++)
				c[i][j] = sec[2];
		fl = 1;
	}

	if (!fl){
		cout << -1 << endl;
		return 0;
	}
	cout << w << endl;
	for (int i = 0; i < w; i++){
		for (int j = 0; j < w; j++)
			cout << c[i][j];
		cout << "\n";
	}

	
	return 0;
}