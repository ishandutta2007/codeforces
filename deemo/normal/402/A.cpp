#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int k, a, b, v;	cin >> k >> a >> b >> v;
	int nd = a/ v + bool(a % v);
	for (int i = 1; i <= 1000; i++){
		int ss = min(b + i, i * k);
		if (ss >= nd){
			cout << i << "\n";
			return	0;
		}
	}
	return	0;
}