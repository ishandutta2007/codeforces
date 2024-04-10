#include<iostream>

using namespace std;

bool mark[200];

int main(){
	int n;	cin >> n;
	int a;	cin >> a;
	while (a--){
		int x;	cin >> x;
		mark[x] = 1;
	}
	int b;	cin >> b;
	while (b--){
		int x;	cin >> x;
		mark[x] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (!mark[i]){
			cout << "Oh, my keyboard!\n";
			return	0;
		}
	cout << "I become the guy.\n";
	return	0;	
}