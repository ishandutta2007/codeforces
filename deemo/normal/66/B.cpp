#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 10;

int n, vec[MAXN];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	int maxi = 1;
	for (int i = 0; i < n; i++){
		int ret = 1;
		for (int j = i - 1; j >= 0; j--, ret++)
			if (vec[j] > vec[j + 1])	break;

		for (int j = i +1 ; j < n; j++, ret++)
			if (vec[j] > vec[j - 1])	break;
		maxi = max(maxi, ret);
	}
	cout << maxi << "\n";
	return	0;		
}