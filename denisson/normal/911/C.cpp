#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

const int dd = 1000007;
int was[1000007];

int calc(int a, int b, int c){
	for (int i = 0; i < 1000007; i++) was[i] = 0;
	for (int i = 0; ; i++){
		if (a * i >= dd) break;
		was[a * i] = 1;
	}
	int fr = -1;
	for (int i = 0; i < dd; i++) if (was[i] == 0){
		fr = i;
		break;
	}
	if (fr == -1) return 1;
	for (int i = 0; ; i++){
		if (fr + b * i >= dd) break;
		was[fr + b * i] = 1;
	}
	fr = -1;
	for (int i = 0; i < dd; i++) if (was[i] == 0){
		fr = i;
		break;
	}
	if (fr == -1) return 1;
	for (int i = 0; ; i++){
		if (fr + c * i >= dd) break;
		was[fr + c * i] = 1;
	}
	fr = -1;
	for (int i = 0; i < dd; i++) if (was[i] == 0){
		fr = i;
		break;
	}
	if (fr == -1) return 1;
	return 0;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int ans = calc(a, b, c) + 
				calc(a, c, b) + 
				calc(b, a, c) + 
				calc(b, c, a) + 
				calc(c, a, b) + 
				calc(c, b, a);
	if (ans > 0) cout << "YES";
	else cout << "NO";
}