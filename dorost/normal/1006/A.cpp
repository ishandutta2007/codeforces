#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n,a;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a % 2 == 0){
			a--;
		}
		cout << a << ' '; 
	}
}