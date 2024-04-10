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

map<int, int>	mp;

int main(){
	read_fast;
	int n;
	cin >> n;
	vector<int>	vec(n * n), sec, gec;
	for (int i = 0; i < n * n; i++){
		cin >> vec[i];
		mp[vec[i]]++;
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());	

	for (int i = 0; i < vec.size(); i++){
		if (mp[vec[i]] == 0)	continue;
		sec.pb(vec[i]);
		for (int w = 0; w < gec.size(); w++)
			mp[__gcd(gec[w], vec[i])] -= 2;
		gec.pb(vec[i]);
		mp[vec[i]]--;
	}

	for (int i = 0; i < n; i++)
		cout << sec[i] << " ";
	cout << endl;
    return 0;
}