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
	int n;
	cin >> n;
	vector<pair<int, int>>	vec(n);
	for (int i = 0; i < n; i++){
		cin >> vec[i].first;
		vec[i].second = i + 1;
	}
	sort(vec.begin(), vec.end());
	for (int i = n - 1; i >= 0; i--)
		for (int j = i - 1; j >= 0; j--)
			for (int k = j - 1; k >= 0; k--)
				if (vec[i].first == vec[j].first + vec[k].first){
					cout << vec[i].second << " " << vec[j].second << " " << vec[k].second << endl;
					return 0;
				}
	cout << -1 << endl;
    return 0;
}