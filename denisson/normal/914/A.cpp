#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n;
int a[11111];

bool bad(int x){
	if (x < 0) return 0;
	for (int i = 0; i <= 1011; i++) if (i * i == x) return 1;
	return 0;
}

int main(){
	//srand(time(NULL));
//	freopen("input.txt", "r", stdin);
	//freopen("output2.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int uk = -1;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (!bad(a[i]) && (uk == -1 || a[i] > a[uk])) uk = i;
	}
	cout << a[uk];
}