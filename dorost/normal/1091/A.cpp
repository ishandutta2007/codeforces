#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << min (min (a + 1, b), c - 1) * 3;
}