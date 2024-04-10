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

int mark[1000];

int main(){
	read_fast;
	map<string, int>	mp;
	mp["captain"] = 4;
	mp["man"] = 3;
	mp["woman"] = 2;
	mp["rat"] = 1;
	mp["child"] = 2;
	int n;	cin >> n;
	vector<pair<string, string>>	vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;
	
	for (int i = 0; i < n; i++){
		pair<string, string>	maxi = {"1", "1"};
		int ind = -1;
		for (int j = 0; j < n; j++){
			if (mark[j])	continue;
			if (maxi.first == "1"){
				maxi = vec[j];
				ind = j;
				continue;
			}
			
			if (mp[maxi.second] > mp[vec[j].second])
				maxi = vec[j], ind = j;
		}
		cout << maxi.first << endl;
		mark[ind] = 1;
	}
    return 0;
}