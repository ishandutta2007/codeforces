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

const int MAXN = 3e3 + 100;

int tl, tr, f[MAXN];
string s, t;
vector<pair<int, int>>	ans;

bool ok(int l, int r){
	string ss = "";
	for (; l < r; l++)	ss += t[l];

	int k = 0;
	for (int i = 1; i < (int)ss.size(); i++){
		while (k && ss[k] != ss[i])	k = f[k];
		if (ss[k] == ss[i])	k++;
		f[i + 1] = k;
	}

	k = 0;
	for (int i = 0; i < (int)s.size(); i++){
		while (k && ss[k] != s[i])	k = f[k];
		if (ss[k] == s[i])	k++;
		if (k == (int)ss.size()){
			tr = i + 1;
			tl = i + 1 - (int)ss.size() + 1;
			return	true;
		}
	}

	reverse(s.begin(), s.end());
	k = 0;
	for (int i = 0; i < (int)s.size(); i++){
		while (k && ss[k] != s[i])	k = f[k];
		if (ss[k] == s[i])	k++;
		if (k == (int)ss.size()){
			reverse(s.begin(), s.end());
			tr = (int)s.size() - i;
			tl = tr + (int)ss.size() - 1;
			return	true;
		}
	}
	reverse(s.begin(), s.end());
	return	false;
}

int main(){
	read_fast;
	cin >> s >> t;

	int l = 0, r = 0;
	for (; r < (int)t.size();){
		while (r + 1 <= (int)t.size() && ok(l, r + 1))	r++; 	
		if (l == r){
			cout << -1 << endl;
			return	0;
		}
		ok(l, r);
		ans.push_back({tl, tr});
		l = r;
	}

	cout << (int)ans.size() << endl;
	for (pair<int, int>	v:ans)
		cout << v.first << " " << v.second << "\n";
    return 0;
}