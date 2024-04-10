#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char s[N], t[N];  
int dp[N][N];
int n, m;  
// 0, 1 ,2 3  
struct node{  
    int op;  
    int pos; char c;  
    node(int A=0,int E=0,char D=0):op(A),pos(E), c(D){}  
    void put()
	{  
        if(op== 2)  
            printf("REPLACE %d %c\n", pos, c);  
        else if(op == 0)  
            printf("INSERT %d %c\n", pos +1, c);  
        else if(op == 1)  
            printf("DELETE %d\n", pos);  
    }  
}P;  
void dfs(int a, int b)
{  
    if(a == 0 && b==0)return ;  
    if(s[a] == t[b] && dp[a-1][b-1] == dp[a][b])  
        dfs(a-1, b-1);  
    else  
    {  
        if(a && dp[a-1][b] +1 == dp[a][b])  
        {  
            P = node(1, a);  
            P.put();  
            dfs(a-1, b);  
        }  
        else if(b && dp[a][b-1] +1 == dp[a][b])  
        {  
            P = node(0, a, t[b]);  
            P.put();  
            dfs(a, b-1);  
        }  
        else if(a && b && dp[a-1][b-1] +1 == dp[a][b])  
        {  
            P = node(2, a, t[b]);  
            P.put();  
            dfs(a-1, b-1);  
        }  
    }  
}  

int main()
{  
    int i, j;  
    scanf("%s", s+1);
    scanf("%s", t+1);  
    n = strlen(s+1);  
    m = strlen(t+1);  
    dp[0][0] = 0;  
    for(i = 1; i <= n; i++)  dp[i][0] = i;  
    for(i = 1; i <= m; i++) dp[0][i] = i;  
    for(i = 1; i <= n; i++){
    	for(j = 1; j <= m; j++){
    		dp[i][j] = min(min(dp[i-1][j], dp[i][j-1])+1, dp[i-1][j-1] + (s[i]!=t[j]));
		}
                 
	}    
	printf("%d\n", dp[n][m]);       
		  
    dfs(n, m);  //dp
     
    return 0;  
}