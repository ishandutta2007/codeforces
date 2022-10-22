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
	read_fast;
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++)
		if ((s[i] == '$' || s[i] == '/') && s[i + 1] == '/')	s[i + 1] = '$';
	string t = "/";
	for (int i = 1; i < s.size(); i++){
		bool fl = 1;
		for (int j = i; j < s.size(); j++)
			if (s[j] != '$' && s[j] != '/')	fl = 0;
		if (fl)	break;
		if (s[i] != '$')	t += s[i];
	}
	cout << t << endl;
    return 0;
}