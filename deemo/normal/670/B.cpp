#include<iostream>

using namespace std;

const int MAXN = 1e5 + 10;

int n, k, id[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> id[i];
	
	for (int i = 0; i < n; i++){
		if (i + 1 < k)
			k -= i+1;
		else{
			cout << id[k - 1] << "\n";
			return 0;
		}
	}
	cout << id[n - 1] << "\n";
	return 0;	
}