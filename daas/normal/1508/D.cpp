#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int MAXN=2010;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,X[MAXN],Y[MAXN],tag[MAXN],father[MAXN],id[MAXN],cur,ans[MAXN*MAXN][2],ANS,dl[MAXN],h,t,pd[MAXN];
double Theta[MAXN];
int find(int k){return father[k]==k?k:father[k]=find(father[k]);}
void solve(int S)
{
	h=t=0;
	dl[++t]=S;
	while(h!=t)
	{
		int u=dl[++h];
		father[u]=S;
		if(tag[u]==S) break;
		dl[++t]=tag[u];
	}
	if(t==1) pd[S]=1;
}
bool cmp(int x,int y){return Theta[x]<Theta[y];}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) X[i]=read(),Y[i]=read(),tag[i]=read();
	for(int i=1;i<=n;++i) if(!father[i]) solve(i);
	for(int i=1;i<=n;++i) if(!pd[i])
	{
		if(!cur) cur=i;
		else if(X[i]<X[cur] || (X[i]==X[cur] && Y[i]<Y[cur])) cur=i;
	}
	for(int i=1;i<=n;++i) Theta[i]=atan2(Y[i]-Y[cur],X[i]-X[cur]);
	for(int i=1;i<=n;++i) id[i]=i;
	sort(id+1,id+n+1,cmp);
	pd[cur]=1;
	for(int i=1,las=0;i<=n;++i) if(!pd[id[i]])
	{
		if(las)
		{
			int alas=find(las),aid=find(id[i]);
			if(alas!=aid)
			{
				father[alas]=aid;
				ans[++ANS][0]=las;
				ans[ANS][1]=id[i];
				swap(tag[las],tag[id[i]]);
			}
		}
		las=id[i];
	}
	while(tag[cur]!=cur)
	{
		ans[++ANS][0]=cur;
		ans[ANS][1]=tag[cur];
		swap(tag[cur],tag[tag[cur]]);
	}
	printf("%d\n",ANS);
	for(int i=1;i<=ANS;++i) printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}