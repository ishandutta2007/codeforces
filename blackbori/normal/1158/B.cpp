#include <bits/stdc++.h>

using namespace std;

int D[101010];
int n, m, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i;
	
	cin >> n >> m;
	
	k = (n - m >> 1) + 1;
	
	for(i=0; i<n; i++){
		if(i % k == k - 1) D[i] = 0;
		else D[i] = 1;
	}
	
	for(i=0; i<n; i++){
		cout << D[i];
	}
	
	cout << endl;
	
	return 0;
}