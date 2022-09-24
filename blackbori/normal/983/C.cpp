#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int A[1010][4], K[11][11][11][11];
int dp[2020][1010];
int n,s,ans = 1e9;

int chk(int x,int l,int r,int y)
{
	int X[5],i,f = -1;
	
	for(i=0;i<4;i++){
		if(l <= A[x][i] && A[x][i] <= r) X[i] = 0;
		else X[i] = A[x][i];
		if(X[i] == 0) f = i;
	}
	
	if(f == -1) return -1;
	else X[f] = y;
	
	sort(X,X+4);
	
	return K[X[0]][X[1]][X[2]][X[3]];
}

int cls(int x,int a)
{
	int i, l = a, r = a;
	
	for(i=0;i<4;i++){
		if(A[x][i] == 0) continue;
		l = min(l, A[x][i]);
		r = max(r, A[x][i]);
	}
	
	return min(r-a, a-l) + r-l;
}

void print(int x)
{
	printf(": %d %d %d %d\n",A[x][0],A[x][1],A[x][2],A[x][3]);
}

int main()
{
	int a,b,c,d,i,j,l,r,x,y,prev,k;
	
	scanf("%d",&n);
	
	for(a=0;a<=9;a++) for(b=a;b<=9;b++){
		for(c=b;c<=9;c++) for(d=c;d<=9;d++){
			s ++;
			A[s][0] = a; A[s][1] = b; A[s][2] = c; A[s][3] = d;
			K[a][b][c][d] = s;
		}
	}
	
	for(i=0;i<=n;i++){
		for(j=1;j<=s;j++) dp[i][j] = 1e7;
	}
	
	dp[0][1] = 0;
	
	prev = 1;
	
	for(k=1;k<=n;k++){
		scanf("%d%d",&a,&b);
		l = min(a, prev); r = max(a, prev);
		
		for(j=1;j<=s;j++){
			for(x=1;x<=l;x++) for(y=r;y<=9;y++){
				c = y-x + y-r + l-x;
				d = chk(j,x,y,b);
				if(d == -1) continue;
				dp[k][d] = min(dp[k-1][j] + c, dp[k][d]); 
			}
		}
		
		prev = a;
	}
/*	
	for(k=1;k<=n;k++){
		for(j=1;j<=s;j++){
			printf("%d %d %d %d : %d\n",A[j][0],A[j][1],A[j][2],A[j][3],dp[i][j]);
		}
		printf("\n");
	}
*/	
	for(i=1;i<=s;i++){
		ans = min(ans, dp[n][i] + cls(i, prev));
	}
	
	printf("%d\n",ans+n+n);
	
	return 0;
}