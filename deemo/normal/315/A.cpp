#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 1e4;

int a[MAX], b[MAX];

int main(){
	int n;	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	int ans = 0;
	for (int i = 0; i < n; i++){
		int x = a[i];
		bool fl = 1;
		for (int j = 0; j < n; j++){
			if (i == j)	continue;
			if (b[j] == x){
				fl = 0;
				break;
			}
		}	
		if (fl)	ans++;
	}
	cout << ans << endl;
	return 0;
}