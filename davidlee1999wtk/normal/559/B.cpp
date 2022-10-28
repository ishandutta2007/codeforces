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
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s1[N],s2[N];
int n;
void solve(char *s,int L,int R)
{
	int m=R-L+1,i;
	if(m%2==1)
		return;
	int mid=(R+L)>>1,flag=0;
	solve(s,L,mid);
	solve(s,mid+1,R);
	for(i=L;i<=mid;i++)
		if(s[i]<s[i-L+mid+1])
		{
			flag=1;
			break;
		}
		else if(s[i]>s[i-L+mid+1])
		{
			flag=-1;
			break;
		}
	if(flag==-1)
		for(i=L;i<=mid;i++)
			swap(s[i],s[i-L+mid+1]);
}

int main()
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	solve(s1,1,n);
	solve(s2,1,n);
	//for(int i=1;i<=n;i++)
		//debug(s2[i]);
	int i,flag=1;
	for(i=1;i<=n;i++)
		if(s1[i]!=s2[i])
			flag=0;
	if(flag)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);