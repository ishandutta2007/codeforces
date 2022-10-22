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

const int MAXN = 500 + 20;

int n;
int vec[MAXN];
int dp[MAXN][MAXN];

int get(int l, int r){
	if (dp[l][r] != -1)
		return	dp[l][r];
	if (r - l == 1)
		return	dp[l][r] = 1;
	if (l >= r)	
		return	dp[l][r] = 0;

	dp[l][r] = get(l + 1, r) + 1;
	for (int i = l + 1; i < r; i++){
		if (vec[l] != vec[i])	continue;
		if (i - l == 1)
			dp[l][r] = min(dp[l][r], get(i + 1, r) + 1);
		else
			dp[l][r] = min(dp[l][r], get(i + 1, r) + get(l + 1, i));
	}
	return	dp[l][r];
}

int main(){
	read_fast;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = -1;

	cout << get(0, n) << endl;
    return 0;
}