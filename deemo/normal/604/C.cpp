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
vector<int>	vec, sec;

void sap(int l, int r){
	for (;l < r; l++)
		if (s[l] == '1')	s[l] = '0';
		else	s[l] = '1';
}

int cal(){
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '1')	ans2 = max(ans2, ans1 + 1);
		else	ans1 = max(ans1, ans2 + 1);
	}	
	return	max(ans1, ans2);
}

int main(){
	read_fast;
	int n;	cin >> n;
	cin >> s;
	
	for (int i = 0; i < n - 1; i++)
		if (s[i] == s[i + 1]){
			if (s[i] == '0')	vec.push_back(i);
			else	sec.push_back(i);
		}

	int ans = cal();
	string temp = s;
	if (vec.size() == 1){
		sap(0, vec.back() + 1);
		ans = max(ans, cal());
		sap(0, vec.back() + 1);
		sap(vec.back() + 1, n);
		ans = max(ans, cal());
		sap(vec.back() + 1, n);
	}
	if (sec.size() == 1){
		sap(0, sec.back() + 1);
		ans = max(ans, cal());
		sap(0, sec.back() + 1);
		sap(sec.back() + 1, n);
		ans = max(ans, cal());
		sap(sec.back() + 1, n);
	}

	if (vec.size() >= 2){
		sap(vec[0] + 1, vec.back() + 1);
		ans = max(ans, cal());
		sap(vec[0] + 1, vec.back() + 1);
	}
	if (sec.size() >= 2){
		sap(sec[0] + 1, sec.back() + 1);
		ans = max(ans, cal());
		sap(sec[0] + 1, sec.back() + 1);
	}

	if (vec.size() && sec.size()){
		int f = vec[0] + 1, g = sec.back() + 1;
		if (f > g)	swap(f, g);
		sap(f, g);
		ans = max(ans, cal());
	}
	cout << ans << endl;
    return 0;
}