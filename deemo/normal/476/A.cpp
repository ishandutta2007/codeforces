#include<iostream>

using namespace std;

int n , m , c , d;

int main(){
    cin >> n >> m;
    if (n < m ){
	 cout << -1 << endl;
	 return 0;
    }	 
    if (n % 2 == 0) c = n / 2;
    else    c = n/2 + 1;
    
    if (c <= m)  d = m - c;
    else    d = m - (c % m);
    if (c % m == 0) d = 0;
    cout << c + d << endl;

    return 0;
}