#include <bits/stdc++.h>

using namespace std;

string S;
int A[2020202], P[2020202];
int L[2020202], R[2020202];
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, i, j, m, mv, mi;

	cin >> t;

	for(; t --; ){
		cin >> S; n = S.size();
		for(i = 0; i < n; i ++){
			A[i << 1 | 1] = S[i];
		}
		for(i = 1, j = 0; i <= n + n - 1; i ++){
			if(i > j + P[j]) P[i] = 0;
			else P[i] = min(P[j + j - i], j + P[j] - i);
			for(; i - P[i] > 1 && i + P[i] < n + n - 1 && 
				A[i - P[i] - 1] == A[i + P[i] + 1]; P[i] ++);
		}
		for(i = n, j = n; i <= n + n - 1; i ++){
			for(; j <= i && j + P[j] < i; j ++);
			L[i] = i - j + 1;
		}
		for(i = n, j = n; i >= 1; i --){
			for(; j >= i && j - P[j] > i; j --);
			R[i] = j - i + 1;
		}
		mv = max(R[1], L[n - 1 << 1 | 1]); mi = 0;
		for(i = 1; i + i <= n; i ++){
			if(S[i - 1] != S[n - i]) break;
			if(i + i == n) m = n;
			else m = i + i + max(R[i << 1 | 1], L[n - i - 1 << 1 | 1]);
			if(m > mv) mv = m, mi = i;
		}
		mv -= mi * 2;
		for(i = 0; i < mi; i ++) cout << S[i];
		if(R[mi << 1 | 1] > L[n - mi - 1 << 1 | 1]){
			for(i = 0; i < mv; i ++) cout << S[mi + i];
		}
		else{
			for(i = 0; i < mv; i ++) cout << S[n - mi - i - 1];
		}
		for(i = mi - 1; i >= 0; i --) cout << S[i];
		cout << "\n";
	}
	
	return 0;
}