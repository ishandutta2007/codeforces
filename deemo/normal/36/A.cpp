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
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;
	string s;
	fin >> s;
	vector<int>	vec;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1')
			vec.pb(i);

	bool fl = 1;
	for (int i = 1; i < vec.size() - 1; i++)
		if (vec[i] - vec[i - 1] != vec[i + 1] - vec[i])	fl = 0;
	
	if (fl)	fout << "YES" << endl;
	else	fout << "NO" << endl;
    return 0;
}