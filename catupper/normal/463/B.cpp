#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;

int a, n, ans;
int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a;
		ans = max(ans, a);
	}
	cout << ans << endl;
}