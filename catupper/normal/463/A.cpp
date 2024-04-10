#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;


int res = -1, n, s, x, y;
int main(){
	cin >> n >> s;
	s *= 100;
	for(int i = 0;i < n;i++){
		cin >> x >> y;
		if(x * 100 + y > s)continue;
		if(y == 0)res = max(res, 0);
		else res = max(res, 100 - y);
	}
	cout << res << endl;
}