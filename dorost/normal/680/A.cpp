#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int a[5], sum = 0;
	for(int i = 0; i < 5; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + 5);
	int max = 0;
	for(int i = 0; i < 3; i++){
		if(a[i] == a[i + 1] && a[i] == a[i + 2]){
			if(max < a[i] + a[i + 1] + a[i + 2])
				max = a[i] + a[i + 1] + a[i + 2];
		}
	}
	for(int i = 0; i < 4; i++){
		if(a[i] == a[i + 1]){
			if(max < a[i] + a[i + 1]){
				max = a[i] + a[i + 1];
			}
		}
	}
	cout << sum - max;
}