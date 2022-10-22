#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;

bool ok(int x){
	int a = x/2;
	int b = x/3;
	int c = x/6;
	
	a -= c;
	b -= c;
	
	int nn = n, mm = m;
	nn -= a;
	mm -= b;

	if (max(0, nn) + max(0, mm) <= c)
		return	true;
	return	false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; ; i++)
		if (ok(i)){
			cout << i << "\n";
			return	0;
		}
	return	0;	
}