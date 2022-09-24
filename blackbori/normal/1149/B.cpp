#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int dp[255][255][255];
int K[33][220202];
int s1[255], s2[255], s3[255];
char str[202020];
int p1, p2, p3;
int n, q;

void f1()
{
	int i, j, k, t;
	
	for(i=p1; i<=p1; i++){
		for(j=0; j<=p2; j++){
			for(k=0; k<=p3; k++){
				t = inf;
				
				if(i > 0 && dp[i - 1][j][k] != inf){
					if(t == inf) t = K[s1[i]][dp[i - 1][j][k]];
					else t = min(t, K[s1[i]][dp[i - 1][j][k]]);
				}
				
				if(j > 0 && dp[i][j - 1][k] != inf){
					if(t == inf) t = K[s2[j]][dp[i][j - 1][k]];
					else t = min(t, K[s2[j]][dp[i][j - 1][k]]);
				}
				
				if(k > 0 && dp[i][j][k - 1] != inf){
					if(t == inf) t = K[s3[k]][dp[i][j][k - 1]];
					else t = min(t, K[s3[k]][dp[i][j][k - 1]]);
				}
				
				dp[i][j][k] = t;
			}
		}
	}
}

void f2()
{
	int i, j, k, t;
	
	for(i=0; i<=p1; i++){
		for(j=p2; j<=p2; j++){
			for(k=0; k<=p3; k++){
				t = inf;
				
				if(i > 0 && dp[i - 1][j][k] != inf){
					if(t == inf) t = K[s1[i]][dp[i - 1][j][k]];
					else t = min(t, K[s1[i]][dp[i - 1][j][k]]);
				}
				
				if(j > 0 && dp[i][j - 1][k] != inf){
					if(t == inf) t = K[s2[j]][dp[i][j - 1][k]];
					else t = min(t, K[s2[j]][dp[i][j - 1][k]]);
				}
				
				if(k > 0 && dp[i][j][k - 1] != inf){
					if(t == inf) t = K[s3[k]][dp[i][j][k - 1]];
					else t = min(t, K[s3[k]][dp[i][j][k - 1]]);
				}
				
				dp[i][j][k] = t;
			}
		}
	}
}

void f3()
{
	int i, j, k, t;
	
	for(i=0; i<=p1; i++){
		for(j=0; j<=p2; j++){
			for(k=p3; k<=p3; k++){
				t = inf;
				
				if(i > 0 && dp[i - 1][j][k] != inf){
					if(t == inf) t = K[s1[i]][dp[i - 1][j][k]];
					else t = min(t, K[s1[i]][dp[i - 1][j][k]]);
				}
				
				if(j > 0 && dp[i][j - 1][k] != inf){
					if(t == inf) t = K[s2[j]][dp[i][j - 1][k]];
					else t = min(t, K[s2[j]][dp[i][j - 1][k]]);
				}
				
				if(k > 0 && dp[i][j][k - 1] != inf){
					if(t == inf) t = K[s3[k]][dp[i][j][k - 1]];
					else t = min(t, K[s3[k]][dp[i][j][k - 1]]);
				}
				
				dp[i][j][k] = t;
			}
		}
	}
}

int main()
{
	int i, j, t, a;
	char st1[3], st2[3];
	
	scanf("%d%d%s", &n, &q, str + 1);
	
	for(i=25; i>=0; i--){
		t = inf;
		for(j=n; j>=0; j--){
			K[i][j] = t;
			if(str[j] == i + 'a') t = j;
		}
	}
	
	for(i=0; i<q; i++){
		scanf("%s%d", st1, &a);
		
		if(*st1 == '+'){
			scanf("%s", st2);
			if(a == 1) s1[++ p1] = *st2 - 'a', f1();
			else if(a == 2) s2[++ p2] = *st2 - 'a', f2();
			else s3[++ p3] = *st2 - 'a', f3();
		}
		else{
			if(a == 1) p1 --;
			else if(a == 2) p2 --;
			else p3 --;
		}
		
		printf("%s\n", dp[p1][p2][p3] != inf? "YES" : "NO");
	}
	
	return 0;
}