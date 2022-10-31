#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int INF = 2e9;

int main() {	
	int n;
	cin >> n;
	ll Mx=-INF,mx=INF,My=-INF,my=INF;
	while(n--) {
		ll x,y;
		cin >> x >> y;
		Mx = max(Mx,x);
		mx = min(mx,x);
		My = max(My,y);
		my = min(my,y);
	}
	ll q = max(Mx-mx,My - my);
	cout << q*q << "\n";

}