#include<iostream>
#include<algorithm>

using namespace std;

int v[10800];
int n, m, x, y, res;

int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++)cin >> v[i];
	for(int i = 0;i < m;i++){
		cin >> x >> y;
		x--,y--;
		res += min(v[x], v[y]);
	}
	cout << res << endl;
	return 0;
}