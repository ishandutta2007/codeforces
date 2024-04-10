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

string s;

bool ok(int l, int r){
	int size = r - l + 1;
	for (int i = 0; i + size <= s.size(); i++){
		if (i == l)	continue;
		bool fl = 1;	
		for (int j = i; j < i + size; j++)
			if (s[j] != s[l + (j - i)])	fl = 0;
		if (fl)	return	true;
	}	
	return	false;
}

int main(){
	cin >> s;
	int ans = 0;
	int n = s.size();
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (ok(i, j))
				ans = max(ans, j - i + 1);
	cout << ans << endl;
    return 0;
}