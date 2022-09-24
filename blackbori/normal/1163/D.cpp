#include <bits/stdc++.h>

using namespace std;

char C[1010], S[55], T[55];
int F1[55], F2[55];
int dp[1010][55][55];
int n, m, ans;

int main()
{
	char chl, chr;
	int i, j, k, i_, j_, c;
	
	scanf("%s%s%s", C, S, T);
	
	n = strlen(S);
	
	for(i=1, j=0; i<n; ){
		if(S[i] == S[j]) F1[i++] = ++j;
		else if(j) j = F1[j - 1];
		else i++;
	}
	
	m = strlen(T);
	
	for(i=1, j=0; i<m; ){
		if(T[i] == T[j]) F2[i++] = ++j;
		else if(j) j = F2[j - 1];
		else i++;
	}
	
	
	for(k=0; k == 0 || C[k - 1]; k++){
		for(i=0; i<=n; i++){
			for(j=0; j<=m; j++){
				dp[k][i][j] = -1e9;
			}
		}
	}
	
	dp[0][0][0] = 0;
	
	for(k=1; C[k - 1]; k++){
		if(C[k - 1] == '*') chl = 'a', chr = 'z';
		else chl = chr = C[k - 1];
		
		for(; chl<=chr; chl++){
			for(i=0; i<=n; i++){
				for(j=0; j<=m; j++){
					c = 0;
					
					for(i_=i; ; ){
						if(i_ < n && S[i_] == chl){
							i_ ++; break;
						}
						else if(i_) i_ = F1[i_ - 1];
						else break;
					}
					
					if(i_ == n) c ++;
					
					for(j_=j; ; ){
						if(j_ < m && T[j_] == chl){
							j_ ++; break;
						}
						else if(j_) j_ = F2[j_ - 1];
						else break;
					}
					
					if(j_ == m) c --;
					
					dp[k][i_][j_] = max(dp[k][i_][j_], dp[k - 1][i][j] + c);
				}
			}
		}
	}
	
	k --; ans = -1e9;
	
	for(i=0; i<=n; i++){
		for(j=0; j<=m; j++){
			ans = max(ans, dp[k][i][j]);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}