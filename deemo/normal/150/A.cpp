#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
	ll n;	cin >> n;
	vector<ll>	vec;
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0)	vec.push_back(i);
	if (vec.size() == 1){
		if (n % (vec[0] * vec[0]) == 0 && n != vec[0] * vec[0]){
			cout << 1 << endl;
			cout << vec[0] * vec[0] << endl;
			return 0;	
		}
		cout << 2 << endl;
	}
	else{
		cout << 1 << endl;
		if (vec.size() == 0){
			cout << 0 << endl;
			return 0;
		}
		if (vec[1] % vec[0] == 0)
			cout << vec[1] << endl;
		else
			cout << vec[0] * vec[1] << endl;
	}
	return 0;
}