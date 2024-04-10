#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main(){
	ld a, b, c, d;
	cin >> a >> b >> c >> d;
	int aa = max(a - (a / 250 * c), 3 * a / 10), bb = max(b - (b / 250 * d), 3 * b / 10);	
	if (aa == bb){
		cout << "Tie";
	}else if(aa > bb){
		cout << "Misha";
	}else{
		cout << "Vasya";
	}
}