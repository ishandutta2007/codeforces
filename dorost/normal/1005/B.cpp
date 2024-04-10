#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	string a, b;
	cin >> a >> b;
	for(int i = 1; i <= max(a.size(), b.size()); i++){
		if(a[a.size() - i] != b[b.size() - i]){
			cout << (int)a.size() + (int)b.size() - i - i + 2;
			return 0;
		}
	} 
	cout << 0;
}