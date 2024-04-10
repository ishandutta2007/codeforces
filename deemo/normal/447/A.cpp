#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool mark[500];

int main(){
	int n, p;	cin >> p >> n;
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		if (mark[x % p]){
			cout << i + 1 << endl;
			return	0;
		}
		mark[x % p] = 1;
	}
	cout << -1 << endl;
	return	0;
}