#include<cstdio>
const int N=1e6+10;
const int a[103]={0,0,1,1,2,0,3,1,1,0,3,3,2,2,4,0,5,2,2,3,3,0,1,1,3,0,2,1,1,0,4,5,2,7,4,0,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,2,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7,4,8,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,9,3,3,0,1,1,3,0,2,1,1,0,4,5,3};
const int b[35]={1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,2,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7,4,8};
int SG(int x)
{
	if(x<=100) return a[x];
	else return b[(x-70)%34];
}
void output(int x)
{
	if(x) printf("Alice");
	else printf("Bob");
	printf("\n");
}
int n,T,p[N],t[2],ans;
char str[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,str);
		t[0]=t[1]=ans=0;
		for(int i=1;i<=n;i++)
			t[p[i]=(str[i-1]=='R')]++;
		if(t[0]!=t[1]) output(t[1]>t[0]);
		else
		{
			for(int i=1,j;i<n;i++)
			{
				if(p[i+1]!=p[i])
				{
					j=i+1;
					while(j<n&&p[j+1]!=p[j]) j++;
					ans^=SG(j-i+1);
					i=j;
				}
			}
			output(ans);
		}
	}
}