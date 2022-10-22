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
typedef long double ld;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

const ld PI = 3.14159265358979323;

int main(){
	read_fast;
	setprecision(12);
	ld x1, y1, r1, x2, y2, r2;	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	if (r1 > r2){
		swap(r1, r2);
		swap(x1, x2);
		swap(y1, y2);
	}

	ld dx = abs(x1 - x2), dy = abs(y1 - y2);
	ld c = sqrt(dx * dx + dy * dy);
	if (c >= r1 + r2){
		cout << 0 << endl;
		return 0;
	}

	if (c + r1 <= r2){
		ld ans = r1 * r1 * PI;
		cout << ans << endl;
		return 0;
	}

	ld cba = (r2 * r2 + c * c - r1 * r1)	/ (r2 * c * ld(2.0));
	cba = acos(cba);
	ld cbd = cba * ld(2.0);
	ld cab = (r1 * r1 + c * c - r2 * r2) / (r1 * c * ld(2.0));
	cab = acos(cab);
	ld cad = cab * ld(2.0);
	ld ans = (cbd) * ld(0.5) * r2 * r2 - r2 * r2 * sin(cbd) * ld(0.5)
		+ cad * ld(0.5) * r1 * r1 - r1 * r1 * ld(0.5) * sin(cad);
	cout << ans << endl;
    return 0;
}