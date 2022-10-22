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
typedef long double ld;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

const int MAX = 1e7 + 10;

vector<pair<ll, ll>>	vec;
ld save[MAX];

ld check(ld n, ld m){
	ld ret = n * n * m + save[ll(n) - 1];
	ld t = n * (n - 1) / 2;
	ret -= (n + m) * t;
	return	ret;
}

void init(){
	for (ld i = 1; i < 1e7; i++)
		save[ll(i)] = save[ll(i) - 1] + i * i;
}

int main(){
	read_fast;
	init();
	ld x;	cin >> x;
	for (ld i = 1; check(i, i) <= x; i++){//minimum	
		ld b = i, e = ll(x)/i + 5, mid, ret = -1;//XXX saghf ro check kon
		while (b <= e){
			mid = ll(b + e)/ 2;
			ld z = check(i, mid);
			if (z <= x){
				b = mid + 1;
				if (abs(z - x) <= 0.0000001){
					ret = mid;
					break;
				}
			}
			else	e = mid - 1;
		}
		if (ret != -1){
			vec.push_back({i, ret});
			vec.push_back({ret, i});
		}
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].first << " " << vec[i].second << endl;
    return 0;
}