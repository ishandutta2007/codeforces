#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;

int a[MAXN][MAXN], n, k;

int main(){
	cin >> n >> k;
	int cnt = 0;
	for (int i = 0; k && i < n; i++)
		for (int j = i; k && j < n; j++){
			if (i == j){
				k--;
				a[i][j] = 1;
				cnt++;
			}
			else if (k > 1){
				k -= 2;
				a[i][j] = a[j][i] = 1;
				cnt += 2;
			}
		}

	if (k > 1){
		cout << "-1\n";
		return 0;
	}
	else if (k == 1 && cnt == n*n){
		cout << "-1\n";
		return 0;
	}
	else if (k){
		for (int i = n-1; ~i; i--)
			if (a[i][i]){
				a[i][i] = 0;
				break;
			}
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				if (!a[i][j]){
					a[i][j] = a[j][i] = 1;
					goto there;
				}
	}
there:
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}