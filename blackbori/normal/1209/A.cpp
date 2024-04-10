#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[111];
bool chk[111];
int n, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i, j;
	
	cin >> n;
	
	for(i=0; i<n; i++){
		cin >> A[i];
	}
	
	sort(A, A + n);
	
	for(i=0; i<n; i++){
		if(!chk[i]){
			ans ++;
			for(j=i; j<n; j++){
				if(A[j] % A[i] == 0) chk[j] = 1;
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}