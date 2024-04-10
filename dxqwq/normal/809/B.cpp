#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0;
   char ch=getchar();
   while(ch<'0'||ch>'9') ch=getchar();
   while(ch>='0'&&ch<='9') s=s*10+(ch^48),ch=getchar();
   return s;
}
char s[53];
int solve(int l,int r)
{
	if(l>r) return -1;
	if(l==r) return l;
	int mid=(l+r)>>1;
	printf("1 %d %d\n",mid,mid+1);
	fflush(stdout);
	scanf("%s",s+1);
	if(s[1]=='T') return solve(l,mid);
	else return solve(mid+1,r); 
}
signed main()
{
    int n=read();read();
    int x=solve(1,n);
    int y=solve(1,x-1);
    if(y==-1) y=x;
    printf("1 %d %d\n",y,x);
    fflush(stdout);
    scanf("%s",s+1);
    if(x==y) s[1]='N';
    if(s[1]=='T')
    {
    	printf("2 %d %d\n",y,x);
	}
	else
	{
		y=solve(x+1,n);
		printf("2 %d %d\n",y,x);
	}
    return 0;
}