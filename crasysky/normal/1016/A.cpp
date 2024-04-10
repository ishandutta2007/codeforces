#include <iostream>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n; ++ i){
		int x;
		cin >> x;
		cnt += x;
		cout << cnt / m << " ";
		cnt %= m;
	}
}