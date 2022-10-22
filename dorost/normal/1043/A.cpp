#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int a[n], max = 0, sum = 0;
	for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > max){
            max = a[i];
        }
        sum += a[i];
	}
	for (int x = max;1; x++){
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans += x - a[i];
        }
        if(ans > sum){
            cout << x;
            break;
        }
	}
}