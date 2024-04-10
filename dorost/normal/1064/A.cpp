#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	int m = a[2] - (a[1] + a[0]) + 1;
	if(m > 0){
		cout << m;
	}else{
		cout << 0;
	}
}