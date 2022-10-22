#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 10;

int n, d, h;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d >> h;
	if (2 * h < d || (n > 2 && d == 1)){
		cout << "-1\n";
		return	0;	
	}
	int td = d;
	for (int i = 1; i <= h; i++)
		cout << i << " " << i + 1 << "\n";
	int cur = h + 2;
	d -= h;
	if (d){
		cout << 1 << " " << cur++ << "\n";
		d--;
		while (d--){
			cout << cur - 1 << " " << cur << "\n";
			cur++;
		}
	}
	if (h < td){
		while (cur <= n)
			cout << 1 << " " << cur++ << "\n";
	}
	else{
		while (cur <= n)
			cout << 2 << " " << cur++ << "\n";
	}
	return	0;
}