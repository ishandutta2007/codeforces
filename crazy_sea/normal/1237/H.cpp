#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=4e3+10;
int t[4],a[N],b[N],n,T,w,ans[N],len,pp;
char str[N];
void rev(int x)
{
	if(x==0) return;
	ans[++len]=x*2;
	reverse(a,a+x);
	for(int i=0;i<x;i++)
		if(a[i]<2) a[i]^=1;
}
void rev2(int x)
{
	pp=x*2;
	reverse(b,b+x);
	for(int i=0;i<x;i++)
		if(b[i]<2) b[i]^=1;
}
bool check()
{
	for(int i=0;i<4;i++) t[i]=0;
	for(int i=0;i<n/2;i++)
		t[a[i]]++,t[b[i]]--;
	return t[2]==0&&t[3]==0;
}
int fd(int x,int y)
{
	while(a[x]!=y)
	{
		if(x>=n/2) printf("!!");
		x++;
	}
	return x;
}
int type(char x,char y)
{return (x==y)*2+(x-'0');}
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		pp=0;
		scanf("%s",str);
//		printf("%s\n",str);
		n=strlen(str);
		for(int i=0;i<n;i++) a[i]=b[i]=0;
		for(int i=0;i<n;i+=2)
			a[i>>1]=type(str[i],str[i+1]);
		scanf("%s",str);
//		printf("%s\n",str);
		for(int i=0;i<n;i+=2)
			b[i>>1]=type(str[i],str[i+1]);
		if(!check()){printf("-1\n");continue;}
		if(t[0]!=0)
		{
			for(int i=0;i<n/2;i++)
			{
				t[a[i]]--,t[a[i]^1]++;
				if(t[0]==0){rev(i+1);break;}
			}
			if(len==0)
			{
				for(int i=0;i<n/2;i++)
					t[a[i]]++,t[a[i]^1]--;
				for(int i=0;i<n/2;i++)
				{
					t[b[i]]++,t[b[i]^1]--;
					if(t[0]==0) {rev2(i+1);break;}
				}
			}
		}
		for(int i=0;i<n/2-1;i++)
			w=fd(i,b[i]),rev(w),rev(w+1);
		rev(n/2-1);
		printf("%d\n",len+(bool)pp);
		for(int i=1;i<=len;i++) printf("%d ",ans[i]);
		if(pp) printf("%d",pp);
		printf("\n");
		len=0;
	}
//	fclose(stdin);
//	fclose(stdout);
}