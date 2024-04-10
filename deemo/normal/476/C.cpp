#include<iostream>

using namespace std;

long long int a , b;
long long sum;
const int q = 1e9 + 7;
typedef long long ll;

int main(){
    cin >> a >> b;
    ll z = ((a * (a + 1)) / 2) % q;
    for (ll i = 1 ; i < b ; i++){
	 sum += ll(i * a);
	 sum %= q;
	 ll temp = ll(i * b) % q;
	 temp = ll(temp * z) % q;
	 sum += temp;
	 sum %= q;
    }
    cout << sum << endl;
    return 0;
}