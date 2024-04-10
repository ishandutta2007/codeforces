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

const int max_n = 1e3;

int n, T;
vector<int>	vec(max_n), sec;
int d[max_n], c[max_n];

int main(){
	read_fast;
	cin >> n >> T;
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	for (int i = 0; i < min(T, (int)8e4); i++){
		for (int j = 0; j < n; j++){
			int pos = upper_bound(sec.begin(), sec.end(), vec[j]) - sec.begin();
			if (pos == sec.size())
				sec.pb(vec[j]);
			else	sec[pos] = vec[j];
			c[j] = (pos + 1) - d[j];
			d[j] = pos + 1;
		}
	}
	int maxi = 0, ind = -1;
	for (int i = 0; i < n; i++){
		if (maxi < d[i]){
			maxi = d[i];
			ind = i;
		}
	}
		
	for (int i = min((int)8e4, T); i < T; i++)
		maxi += c[ind];
	cout << maxi << endl;
    return 0;
}