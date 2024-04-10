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

char c[200][200];

int main(){
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			cin >> c[i][j];

	int minx = 200, maxx = -1, miny = 200, maxy = -1;

	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++){
			if (c[i][j] == '.')	continue;
			minx = min(minx, j);
			maxx = max(maxx, j);
			miny = min(miny, i);
			maxy = max(maxy, i);
		}
	for (int i = miny; i <= maxy; i++){
		for (int j = minx; j <= maxx; j++)
			cout << c[i][j];
		cout << endl;
	}
    return 0;
}