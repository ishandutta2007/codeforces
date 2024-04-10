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
	
string s, a, b;

bool ok(){
	int c = 0;
	for (int i = 0; i < s.size(); i++){
		if (c == 0){
			bool fl = 0;
			if (i + a.size() > s.size())	continue;
			for (int j = i; j < i + a.size() && j < s.size(); j++)
				if (s[j] != a[j - i])	fl = 1;
			if (fl)	continue;
			c++;
			i += a.size();
			i -= 1;
		}
		else if (c == 1){
			bool fl = 0;
			if (i + b.size() > s.size())	continue;
			for (int j = i; j < i + b.size(); j++)
				if (s[j] != b[j - i])	fl = 1;
			if (fl)	continue;
			c++;
			break;
		}
	}
	return	c == 2;
}

int main(){
	read_fast;
	cin >> s >> a >> b;
	vector<int>	vec;
	if (ok())	vec.pb(1);
	reverse(s.begin(), s.end());
	if (ok())	vec.pb(2);
	if (vec.size() == 2)	cout << "both" << endl;
	else if (vec.size() == 0)	cout << "fantasy" << endl;
	else if (vec.back() == 1)	cout << "forward" << endl;
    else cout << "backward" << endl;
	return 0;
}