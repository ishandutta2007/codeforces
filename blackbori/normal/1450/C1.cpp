#include <bits/stdc++.h>

using namespace std;

string S[333];
int A[3];
int n;

void tc()
{
	int i, j, t;

	cin >> n;

	A[0] = A[1] = A[2] = 0;
	
	for(i = 0; i < n; i ++){
		cin >> S[i];
		for(j = 0; j < n; j ++){
			if(S[i][j] == 'X') A[(i + j) % 3] ++;
		}
	}

	t = min_element(A, A + 3) - A;
	
	for(i = 0; i < n; i ++){
		for(j = 0; j < n; j ++){
			if(S[i][j] == 'X' && (i + j) % 3 == t){
				S[i][j] = 'O';
			}
		}
		cout << S[i] << "\n";
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;

	for(; t --; ){
		tc();
	}
}