#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int s[]={0,4,8,15,16,23,42},ans[7];
bool vis[7];
void get(int i,int j,int &x,int &y)
{
	printf("? %d %d\n",i,j);
	fflush(stdout);
	int w;
	scanf("%d",&w);
	for(int i=1;i<=6;++i)
		for(int j=i+1;j<=6;++j)
			if(s[i]*s[j]==w)
			{
				x=i,y=j;
				return;
			}
}
int main()
{
	int a1,a2,b1,b2,c1,c2,d1,d2;
	get(1,2,a1,a2);
	get(3,4,b1,b2);
	get(1,3,c1,c2);
	get(1,5,d1,d2);
	if(a1==c1||a1==c2)ans[1]=a1,ans[2]=a2;
	else ans[1]=a2,ans[2]=a1;
	if(b1==c1||b1==c2)ans[3]=b1,ans[4]=b2;
	else ans[3]=b2,ans[4]=b1;
	vis[a1]=vis[a2]=vis[b1]=vis[b2]=1;
	if(ans[1]==d1)ans[5]=d2,vis[d2]=1;
	else ans[5]=d1,vis[d1]=1;
	for(int i=1;i<=6;++i)
		if(!vis[i])ans[6]=i;
	printf("! ");
	for(int i=1;i<=6;++i)
		printf("%d ",s[ans[i]]);
	fflush(stdout);
	return 0;
}