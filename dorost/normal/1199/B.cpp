#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll h,l;
	cin >> h >> l;
	cout << fixed << setprecision(7) <<  (l * l - h * h) / (2.0 * h);
}