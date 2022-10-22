#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int a, b, c, d, e, f;

int cnt(int x){
	return x * x;
}

int main(){
	cin >> a >> b >> c >> d >> e >> f;
	cout << cnt(a + b + c) - cnt(a) - cnt(c) - cnt(e) << endl;
	return 0;	
}