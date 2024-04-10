#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MN 200000
char a[MN+5],b[MN+5];
void solve(char*s,int l,int r)
{
	if((r-l+1)&1)return;
	int mid=l+r>>1,i;
	solve(s,l,mid);solve(s,mid+1,r);
	for(i=0;i<=mid-l;++i)
		if(s[l+i]!=s[mid+1+i])
			if(s[l+i]<s[mid+1+i])return;
			else break;
	for(i=0;i<=mid-l;++i)swap(s[l+i],s[mid+1+i]);
}
int main()
{
	int n,i;
	scanf("%s%s",a+1,b+1);n=strlen(a+1);
	solve(a,1,n);solve(b,1,n);
	for(i=1;i<=n;++i)if(a[i]!=b[i])return 0*puts("NO");
	puts("YES");
}