#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define b begin()
#define e end()

int n, k, A[300000];
ll done[5001][5001];

int main() {
	cin >> n >> k;
	F0R(i,n) scanf("%d",&A[i]);
	sort(A,A+n);
	int x = n/k, y = n%k;
	FOR(i,1,k+1) F0R (j, min(y,i)+1) {
		if (j == 0) done[i][0] = done[i-1][0]+A[x*i-1]-A[x*(i-1)];
		else if (i == j) done[i][j] = done[i-1][j-1]+A[x*i+j-1]-A[x*(i-1)+j-1];
		else {
			done[i][j] = done[i-1][j-1]+A[x*i+j-1]-A[x*(i-1)+j-1];
			done[i][j] = min(done[i][j],done[i-1][j]+A[x*i+j-1]-A[x*(i-1)+j]);
		}
	}
	cout << done[k][y];
	return 0;
}