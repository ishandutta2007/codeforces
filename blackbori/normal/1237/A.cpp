#include <bits/stdc++.h>

using namespace std;

int A[20202];
int n, s, x, y;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i;
	
	cin >> n;
	
	for(i=0; i<n; i++){
		cin >> A[i];
		s += A[i] / 2;
	}
	
	if(s < 0) x = -s, y = 0;
	else x = 0, y = s;
	
	for(i=0; i<n; i++){
		if(A[i] & 1){
			if(x && A[i] > 0) cout << (A[i] + 1) / 2 << "\n", x --;
			else if(y && A[i] < 0) cout << (A[i] - 1) / 2 << "\n", y --;
			else cout << A[i] / 2 << "\n";
		}
		else cout << A[i] / 2 << "\n";
	}
	
	return 0;
}