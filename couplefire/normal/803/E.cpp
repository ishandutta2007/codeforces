#include <bits/stdc++.h>
using namespace std;
int n,k;
char s[1234];
bool vis[1234][2345];
bool dfs(int i,int j)
{
	if (i == n - 1 && (j > k || j < -k)) return false;
  	if (i < n - 1 && (j >= k || j <= -k)) return false;
  	if (i < 0) return j == 0;
  	if (vis[i][1234+ j]) return false;
  	
  	char c;
  	if (((s[i] == (c = 'D') || s[i] == '?') && dfs(i - 1, j)) 
	  	||((s[i] == (c = 'W') || s[i] == '?') && dfs(i - 1, j - 1)) 
	  	||((s[i] == (c = 'L') || s[i] == '?') && dfs(i - 1, j + 1))
	  )
	  {
    	printf("%c", c);
   		 return true;
  	  }
  vis[i][1234 + j] = true;
  return false;
	
}
int main()
{
	cin>>n>>k>>s;
	if(!dfs(n-1,k) && !dfs(n-1,-k))
	{
		puts("NO");
	}
	puts("");
	return 0;
}