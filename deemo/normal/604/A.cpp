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

double a[10], b[10];

int main(){
	double ans = 0;
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	for (int i = 0; i < 5; i++)
		cin >> b[i];
	int c, d;	cin >> c >> d;
	ans += c * 100;
	ans -= d * 50;
	for (int i = 1; i <= 5; i++){
		ans += max(0.3 * (i * 500), (1.0 - double(a[i - 1])/250.0) * double(i * 500) - (50.0 * b[i - 1]));
	}
	cout << ans << endl;
    return 0;
}