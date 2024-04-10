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

bool pr(int x){
	if (x == 1)	return	false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)	return false;
	return	true;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int>	vec;
	for (int i = 2; i <= n; i++)
		if (pr(i))	vec.pb(i);

	int cnt = 0;
	for (int i = 2; i <= n; i++){
		if (!pr(i))	continue;
		for (int j = 0; j < vec.size() - 1; j++)
			if (i == 1 + vec[j] + vec[j + 1]){
				cnt++;
				break;
			}
	}
	if (cnt >= k)
		cout << "YES" << endl;
	else	
		cout << "NO" << endl;
    return 0;
}