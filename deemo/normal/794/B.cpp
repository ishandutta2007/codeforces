#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, h;
ld z;

bool check(ld mid, ld x){
	ld zz = (mid/h)*z;
	ld temp = zz*zz;
	temp -= mid*mid;
	ld y = sqrt(temp);
	return y*mid < x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	cin >> n >> h;
	z = sqrt(0.5*0.5+ld(h)*h);
	ld s = h/2.;
	ld x = s/n, cur = 0;
	for (int i = 0; i < n-1; i++){
		cur += x;
		
		ld lo = 0, hi = h;
		for (int i = 0; i < 200; i++){
			ld mid = (hi+lo)/2.;
			if (check(mid, cur))
				lo = mid;
			else
				hi = mid;
		}
		cout << hi << " ";
	}
	cout << "\n";
	return 0;
}