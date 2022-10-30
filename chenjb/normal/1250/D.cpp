#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
const int N=1005;
char s[N*N],ans[N][N];
int n,l,k;
int main()
{
	scanf("%d%d%d",&n,&l,&k);
	scanf("%s",s+1);
	sort(s+1,s+n*l+1);
	int top=0;
	rep(i,l){
		int pos=k;
		while(pos-1>=1&&ans[pos-1][i-1]==ans[k][i-1])--pos;
		for(int j=pos;j<=k;++j)ans[j][i]=s[++top];
	}
	rep(i,n)rep(j,l)if(ans[i][j]=='\0')ans[i][j]=s[++top];
	rep(i,n)printf("%s\n",ans[i]+1);
	return 0;
}