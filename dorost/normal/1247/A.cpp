#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
	int a,b;
	cin >> a >> b;
    if(a == b - 1){
	 	cout << a << 9 << ' ' << b << 0;
    }else if(a == b){
		cout << a << 5 << ' ' << b << 6; 
	}else if(a == 9 && b == 1){
		cout << a << 9 << ' '  << b << "00"; 
	}else{
		cout << -1;
	}		
}