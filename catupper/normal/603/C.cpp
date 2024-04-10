#include<iostream>
#include<algorithm>

using namespace std;

int n, k, a;


int odd(int x){
	if(x == 1)return 1;
	if(x == 2)return 0;
	if(x == 3)return 1;
	if(x == 4)return 2;
	if(x == 5)return 0;
	if(x == 6)return 2;
	if(x % 2 == 1)return 0;
	int res = odd(x / 2);
	if(res == 0)return 1;
	return 3 - res;
}

int even(int x){
	if(x == 1)return 1;
	if(x == 2)return 2;
	if(x % 2 == 0)return 1;
	return 0;
}

int main(){
	cin >> n >> k;
	int res = 0;
	for(int i = 0;i < n;i++){
		cin >> a;
		if(k % 2 == 1)a = odd(a);
		else a = even(a);
		
		res ^= a;
	}
	if(res == 0)cout << "Nicky" << endl;
	else cout << "Kevin" << endl;
	return 0;
}