#include <bits/stdc++.h>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define ll long long
//#define file
using namespace std;

int T,i,j,k,l;
int n,m,A,B,ans;
int s[200001];

void swap(int &x,int &y) {int z=x;x=y;y=z;}

int main()
{
	#ifdef file
	freopen("d.in","r",stdin);
	#endif
	
	scanf("%d",&T);
	for (;T;--T)
	{
		scanf("%d%d%d%d",&n,&m,&A,&B);ans=0;
		if (A>B) A=n-A+1,B=n-B+1;
		fo(i,1,m) scanf("%d",&s[i]);
		
		sort(s+1,s+m+1);k=1;
		fd(i,m,1) if (k+s[i]<=B-1) ++k,++ans;
		ans=min(ans,B-A-1);
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}