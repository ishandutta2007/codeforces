#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, sum,mini = 0,maxi = 0;
	cin >> n >> sum;
	int x[n], y[n];
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		maxi += y[i];
		mini += x[i];
	}
	if(sum >= mini && sum <= maxi){
		cout << "YES\n";
		int ans = sum - mini; 
		for(int i = 0; i < n; i++){
			if(ans > y[i] - x[i]){
				ans -=  y[i] - x[i];
				cout << y[i] << ' ';
			}else{
				cout << x[i] + ans << ' ';
				ans = 0;
			}
		}
	}else
		cout << "NO";
}