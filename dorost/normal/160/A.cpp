#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int a[n], sum = 0, x = 0;
	for (int i = 0 ; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	for(int i = 0; i < n; i++){
		x += a[i];
		if(x + x > sum){
			cout << i + 1;
			 break;
		}
	}
}