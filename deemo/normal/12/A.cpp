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

char c[3][3];

int main(){
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> c[i][j];
	bool fl = 0;
	if (c[0][0] != c[2][2])	fl = 1;
	if (c[0][1] != c[2][1])	fl = 1;
	if (c[0][2] != c[2][0])	fl = 1;
	if (c[1][0] != c[1][2])	fl = 1;
	if (fl)	cout << "NO" << endl;
	else	cout << "YES" << endl;
    return 0;
}