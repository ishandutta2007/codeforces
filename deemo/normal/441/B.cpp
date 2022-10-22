#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 3e3 + 20;

int n, v;
int a[MAXN], b[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> v;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	
	int ans = 0, f = 0, g = 0;
	for (int i = 1; i <= 3003; i++){
		f = g;
		g = 0;
		for (int j = 0; j < n; j++)
			if (a[j] == i)	g += b[j];
	
		int z = min(v, f);
		f -= z;	
		ans += z;

		if (z < v){
			z = min(v - z, g);
			g -= z;
			ans += z;
		}
	}	
	cout << ans << endl;
	return	0;
}