#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main(){
	int n;
	cin >> n;
	int a[n];
	int x = 0, max = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++){
	if (a[i] >= a[i + 1]){
			if (x > max){
				max = x;
			}
			x = 0;
		}else{
			x++;
		}
	}
	if (x > max){
		max = x;
	}
	cout << max + 1;
}