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

const int MAX = 500 + 50;

bool mark[MAX][MAX];

int main(){
	read_fast;
	int x, y, a, b;	cin >> x >> y >> a >> b;
	string s;	cin >> s;
	
	int ans = x * y;
	cout << 1 << " ";
	mark[a][b] = 1;
	ans--;
	for (int i = 0; i < s.size() - 1; i++){
		if (s[i] == 'U' && a > 1)	a--;
		if (s[i] == 'D' && a < x)	a++;
		if (s[i] == 'R' && b < y)	b++;
		if (s[i] == 'L' && b > 1)	b--;
		if (mark[a][b])	cout << 0 << " ";
		else{
			cout << 1 << " ";
			ans--;
		}
		mark[a][b] = 1;
	}
	cout << ans << endl;
    return 0;
}