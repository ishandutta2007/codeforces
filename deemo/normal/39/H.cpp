#include<bits/stdc++.h>

using namespace std;

int k;

string get(int x){
	string ret;
	while (x){
		ret += char(x % k + '0');
		x /= k;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	cin >> k;
	for (int i = 1; i < k; i++){
		for (int j = 1; j < k; j++)
			cout << get(i * j) << " ";
		cout << "\n";
	}
	return 0;
}