#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll a;
	cin >> a;
	ll b = 1,c=0;
	while(b*10 <= a)
		b*=10;
	while(c+b <= a)
		c += b;
	cout << c+b-a << "\n";
}