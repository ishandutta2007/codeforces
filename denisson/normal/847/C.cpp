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
ll ww[300007];

void stop(){
	cout << "Impossible";
	exit(0);
}

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;

	ll len = 0;
	ll sum = 0;
	ll cnt = 0;

	while(1){
		if (cnt > n) stop();
		if (len + sum > k) break;
		sum += len;
		cnt++;
		len++;
	}
	for (int i = len - 1; i >= 1; i--){
		while(sum + i <= k){
			ww[i]++;
			sum += i;
			cnt++;
			if (cnt > n) stop();
		}
	}
	while(cnt < n) cnt++, ww[0]++;
	for (int i = 0; i < len; i++) cout << '(';
	for (int i = len - 1; i >= 0; i--){
		cout << ')';
		for (int g = 0; g < ww[i]; g++) cout << "()";
	}
}