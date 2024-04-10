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

const int max_n = 2e5 + 100;

int n;
int a[max_n], nxt[max_n], prv[max_n];
set<pair<int, int>>	st;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	if (n == 2){
		cout << a[n - 1] - a[0] << endl;
		return 0;
	}

	int t = (n-2)/2;
	if (n % 2 == 1)	t++;
	int ans = 1e9;
	for (int i = 0; i <= t; i++)
		ans = min(ans, a[n - 1 - i] - a[t - i]);
	cout << ans << endl;
    return 0;
}