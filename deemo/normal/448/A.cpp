#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int a[4], b[4], aa, bb;
int n;

int main(){
	for (int i = 0; i < 3; i++){
		cin >> a[i];
		aa += a[i];
	}
	for (int i = 0; i < 3; i++){
		cin >> b[i];
		bb += b[i];
	}
	cin >> n;
	int x = aa / 5 + (aa % 5 != 0);
	x += bb / 10 + (bb % 10 != 0);
	if (x <= n)
		cout << "YES\n";
	else
		cout << "NO\n";
	return	0;	
}