#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_prime(int x){
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;
    for(int i = 1; true; i++){
		if(is_prime(n * i + 1) == false){
			cout << i;
			break;
		}
	}
}