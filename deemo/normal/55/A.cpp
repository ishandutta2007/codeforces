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

const int max_n = 2e3;

int mark[max_n];

int main(){
	int n;	cin >> n;	
	int cnt = 0;
	int ind = 0;
	for (int i = 1; i <= 1e7; i++){
		if (mark[ind] == 0)
			cnt++;
		mark[ind] = 1;
		ind = (ind + i) % n;
	}
	if (cnt == n)	cout << "YES" << endl;
	else	cout << "NO" << endl;
    return 0;
}