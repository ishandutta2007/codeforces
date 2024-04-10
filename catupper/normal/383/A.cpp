#include<iostream>
#include<algorithm>

using namespace std;

long long n, res, cnt, a;
int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a;
		cnt += a;
		if(!a)res += cnt;
	}
	cout << res << endl;
	return 0;
}