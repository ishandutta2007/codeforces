#include<iostream>

using namespace std;

const int MAXN = 1e6 + 100;

bool mark[MAXN];

int main(){
	int n;	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int x;	cin >> x;
		mark[x] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (!mark[i]){
			cout << i << endl;
			return	0;
		}
	return 0;	
}