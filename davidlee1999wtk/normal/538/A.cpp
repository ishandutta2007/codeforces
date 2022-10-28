#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[120]={"CODEFORCES#"},now=0;
char p[105];
int main()
{
	int n,i,flag=0,j,k;
	scanf("%s",p+1);
	n=strlen(p+1);
	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n+1;j++)
		{
			now=0;
			for(k=1;k<=n;k++)
				if(k<=i||k>=j)
				{
					if(p[k]!=s[now])
						break;
					now++;
				}
			if(k==n+1&&now==10)
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
CODETFTORCES
CODEFORCEST
*/