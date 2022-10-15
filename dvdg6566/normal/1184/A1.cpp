#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long r;
	
	cin >> r;
	
	if(r % 2 == 0 || r < 4){
		cout << "NO";
	}
	else{
		cout << 1 << " ";
		r -= 3;
		r /= 2;
		cout << r;
	}
	
	return 0;
}