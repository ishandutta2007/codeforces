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
	fio;
	ll s,v1,v2,t1,t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	ll a = s*v1+2*t1;
	ll b = s*v2+2*t2;
	if(a == b) cout << "Friendship\n";
	else if(a < b) cout << "First\n";
	else cout << "Second\n";
	

}