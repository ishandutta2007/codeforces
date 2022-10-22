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

const int max_n = 1e5;

bool mark[max_n];

int main(){
	int n, m;	cin >> n >> m;
	while(m--){
		string s;
		cin >> s;	
		cin >> s;
		cin >> s;
		if (s == "left"){
			cin >> s;
			int x;	cin >> x;
			for (int i = x; i <= n; i++)
				mark[i] = 1;
		}
		else{
			cin >> s;
			int x;	cin >> x;
			for (int i = x; i > 0; i--)
				mark[i] = 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!mark[i])
			cnt++;
	if (cnt == 0)	cout << -1 << endl;
	else	cout << cnt << endl;
    return 0;
}