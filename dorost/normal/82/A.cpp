#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n;
	string t[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
	cin >> n;
	while(n - 5 > 0){
		n = n / 2 - 2;
	}
	cout << t[n - 1];
}