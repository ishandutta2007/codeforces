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



int main() {	
	int n,a=0;
	ll x;
	cin >> n >> x;
	while(n--) {
		string s; int d;
		cin >> s >> d;
		if(s == "+") {
			x += d;
		} else {
			if(x >= d) x-=d;
			else ++a;
		}
	}
	cout << x << " " << a << "\n";
}