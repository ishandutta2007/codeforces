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

string	vec[(int)2e3];

string rotate(string t){
	string s = t;
	s[0] = t[1];
	s[1] = t[3];
	s[2] = t[0];
	s[3] = t[2];
	return	s;
}

int main(){
	read_fast;
	int n;	cin >> n;
	int sz = 0;
	for (int i = 0; i < n; i++){
		string t = "";
		cin >> t;
		string temp;
		cin >> temp;
		t += temp;
		
		for (int j = 0; j < sz; j++){
			if (t == vec[j])	break;
			t = rotate(t);
			if (t == vec[j])	break;
			t = rotate(t);
			if (t == vec[j])	break;
			t = rotate(t);
			if (t == vec[j])	break;
			t = rotate(t);
			if (j == sz - 1)
				vec[sz++] = t;
		}
		if (sz == 0)
			vec[sz++] = t;
		if (i != n - 1)	cin >> t;
	}
	cout << sz << endl;
    return 0;
}