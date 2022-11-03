#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

ll n, k;

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	ll k1 = 0, k2 = 0;
	ll cop = n;
	while(cop % 2 == 0){
		cop /= 2;
		k1++;
	}
	while(cop % 5 == 0){
		cop /= 5;
		k2++;
	}
	while(k1 < k){
		k1++;
		n *= 2;
	}
	while(k2 < k){
		k2++;
		n *= 5;
	}
	cout << n;
}