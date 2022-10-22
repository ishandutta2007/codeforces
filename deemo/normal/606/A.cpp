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
	int a[3], b[3], c[3];
	for (int i = 0; i < 3; i++)	cin >> a[i];
	for (int i = 0; i < 3; i++)	cin >> b[i];
	for (int i = 0; i < 3; i++)	c[i] = a[i] - b[i];
	sort(c, c + 3);
	reverse(c, c + 3);
	while (c[0] > 1){
		c[0] -= 2;
		c[2] += 1;
		sort(c, c + 3);
		reverse(c, c + 3);
	}
	bool flag = 1;
	for (int i = 0; i < 3; i++)
		if (c[i] < 0)	flag = 0;
	if (flag)	cout << "Yes\n";
	else	cout << "No\n";
    return 0;
}