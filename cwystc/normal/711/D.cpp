#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
void putint(LL n)
{
     char a[20];
     int size=0;
     if (n==0)
        putchar('0');
     while (n)
     {
           a[size++]=n%10+48;
           n/=10;
     }
     for (int i=size-1;i>=0;i--)
         putchar(a[i]);
     putchar('\n');
}

int n,a[500000],stack[500000],t,nedge,gr,h,ans,dfn[500000],hed[500000],nxt[500000],too[500000],si,low[500000],e[500000],belong[500000];
bool instack[500000],visited[500000];
const int MO=1e9+7;
void addedge(int x,int y)
{
	nxt[++nedge]=hed[x];
	hed[x]=nedge;
	too[nedge]=y;
}

void tarjan(int x)
{
	low[x]=dfn[x]=++h;
	instack[x]=visited[x]=true;
	stack[++si]=x;
	for (int i=hed[x];i!=0;i=nxt[i])
	{
		int y=too[i];
		if (!visited[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if (instack[y])
			low[x]=min(low[x],low[y]);
	}
	if (dfn[x]==low[x])
	{
		for (gr++;stack[si+1]!=x;si--,e[gr]++)
		{
			instack[stack[si]]=false;
			belong[stack[si]]=gr;
		}
	}
}
int main()
{
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]),addedge(i,a[i]);
	FOR(i,1,n)
		if (!visited[i]) tarjan(i);
	ans=1;
	FOR(i,1,gr)
		if (e[i]==1) ans=ans*2%MO;
		else{
			t=1;
			FOR(j,1,e[i]) t=t*2%MO;
			t=(t+MO-2)%MO;
			ans=(LL)ans*t%MO;
		}
	cout<<ans<<endl;
	return 0;
}