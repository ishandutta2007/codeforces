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

const int max_n = 400;

int n, k;
char mat[max_n][max_n];
int d[max_n][max_n];

bool ok(int t, int pos){
	if (d[t][pos] != -1)	return	d[t][pos];
	if (t == n)	return	true;
	if (t + 2 * t < n && mat[pos][t + 2 * t] != '.' && mat[pos][t + 2 * t] != 's')	return	false;
	
	bool f = 0;
	if (t + 2 * t + 1 >= n || mat[pos][t + 2 * t + 1] == '.')	f |= ok(t + 1, pos);
	if (pos != 0)
		if (t + 2 * t + 1 >= n || mat[pos][t + 2 * t + 1] == '.')
			if (t + 2 * t + 1 >= n || mat[pos - 1][t + 2 * t + 1] == '.')	f |= ok(t + 1, pos - 1);
	if (pos != 2)
		if (t + 2 * t + 1 >= n || mat[pos][t + 2 * t + 1] == '.')
			if (t + 2 * t + 1 >= n || mat[pos + 1][t + 2 * t + 1] == '.')	f |= ok(t + 1, pos + 1);
	return	d[t][pos] = f;
}

int main(){
	read_fast;
	int t;	cin >> t;
	while (t--){
		for (int i = 0; i < max_n; i++)
			for (int j = 0; j < max_n; j++)
				d[i][j] = -1;
		cin >> n >> k;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				cin >> mat[i][j];		

		int pos = 0;
		for (int i = 0; i < 3; i++)	
			if (mat[i][0] == 's')	pos = i;
		if (ok(0, pos))	
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}	
    return 0;
}