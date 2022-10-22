#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int pi, rub;
bool prime[1280000];


string ss(int x){
	if(x == 0)return "";
	return ss(x/10) + (char)('0' + (x%10));	
}

bool pal(int x){
	string str = ss(x);
	string rts = "";
	for(int i = 0;i < str.size();i++){
		rts += str[str.size() - 1 - i];
	}
	return str == rts;
}

int p, q;

int res;
int main(){
	cin >> p >> q;
	fill(prime, prime + 1280000, true);
	prime[0] = prime[1] = false;
	for(int i = 2;i*i < 1280000;i++){
		if(!prime[i])continue;
		for(int j = i * i;j < 1280000;j += i){
			prime[j] = false;
		}
	}
	for(int i = 1;i < 1280000;i++){
		if(prime[i])pi++;
		if(pal(i))rub++;
		if(pi * q <= p * rub)res = i;
	}
	cout << res << endl;
}