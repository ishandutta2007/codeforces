#include<iostream>
#include<algorithm>

using namespace std;

long long x, y, m;
long long fib[1050];

int main(){
    cin >> x >> y >> m;
    if(x > y)swap(x, y);
    if(y >= m){
	cout<< 0 << endl;
	return 0;
    }
    if(y <= 0){
	cout << -1 << endl;
	return 0;
    }
    long long res = 0;
    while(y < m){
	res += (y - x) / y + 1;
	x += ((y - x) / y + 1) * y;
	if(y < x)swap(x, y);
    }
    cout << res << endl;
    return 0;
}