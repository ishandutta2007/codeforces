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
	ll a,b;
	cin >> a >> b;
	if((a/b)&1) cout << "YES\n";
	else cout << "NO\n";
}