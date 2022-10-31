#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int main(){
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    if (x > a){
		cout <<"NO"<< endl;
		return 0;
    }
    b += a - x;
    if (y > b){
		cout << "NO" << endl;
		return 0;
    }
    c += b - y;
    if (z > c){
		cout << "NO" << endl;
		return 0;
    }
    cout << "YES" << endl;
}