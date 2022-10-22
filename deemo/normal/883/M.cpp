
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

int main(){
	int x1 = in(), y1 = in(), x2 = in(), y2 = in();
	int d = abs(x1-x2) + abs(y1-y2);
	d *= 2;
	if (x1 == x2 || y1 == y2)
		d += 6;
	else
		d += 4;
	cout << d << endl;
	return 0;
}