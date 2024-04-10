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

int main(){
	map<string, int>	mp;
	mp["rock"] = 0;
	mp["scissors"] = 1;
	mp["paper"] = 2;
	
	string t[3];
	for (int i = 0; i < 3; i++)
		cin >> t[i];
	int z = (mp[t[0]] + 1) % 3;
	bool fl = 0;
	if (mp[t[1]] == mp[t[2]] && mp[t[1]] == z)	cout << "F" << endl, fl = 1;
    z = (mp[t[1]] + 1) % 3;
	if (mp[t[0]] == mp[t[2]] && mp[t[0]] == z)	cout << "M" << endl, fl = 1;
	z = (mp[t[2]] + 1) % 3;
	if (mp[t[0]] == mp[t[1]] && mp[t[0]] == z)	cout << "S" << endl, fl = 1;
	if (!fl)
		cout << "?" << endl;
	return 0;
}