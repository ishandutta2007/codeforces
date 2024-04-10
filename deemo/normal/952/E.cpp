#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int c1 = 0, c2 = 0;
	while (n--){
		string a, b; cin >> a >> b;
		if (b[0] == 'h')
			c2++;
		else
			c1++;
	}
	if (c2 > c1)
		swap(c1, c2);
	int x = 1;
	while (true){
		if ((x*x+1)/ 2 >= c1 && x*x/2 >= c2) break;
		x++;
	}
	cout << x << endl;
	return 0;
}