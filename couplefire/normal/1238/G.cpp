#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
inline int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
const int MAXN=500005;
struct node
{
	int c,t,o;node(){}node(int _c,int _t,int _o){c=_c;t=_t;o=_o;}
}a[MAXN];int n,m,c,c0;
bool cmp(node n1,node n2){return n1.t<n2.t;}
map<int,LL> mp;
LL solve()
{
	while(mp.size())mp.erase(mp.begin());
	int lst=c0;LL cost=0;mp[0]=c0;
	for(int i=0;i<n;i++)
	{
		int nd=a[i+1].t-a[i].t;
		while(nd>0&&mp.size())
		{
			int gk=min(1LL*nd,mp.begin()->second);
			nd-=gk;cost+=1LL*mp.begin()->first*gk;
			mp.begin()->second-=gk;lst-=gk;
			if(!mp.begin()->second)mp.erase(mp.begin());
		}if(nd>0)return -1;
		int ad=min(a[i+1].o,c-lst);lst+=ad;a[i+1].o-=ad;
		while(a[i+1].o&&mp.size()&&mp.rbegin()->first>a[i+1].c)
		{
			int dl=min(1LL*a[i+1].o,mp.rbegin()->second);
			ad+=dl;mp.rbegin()->second-=dl;a[i+1].o-=dl;
			if(!mp.rbegin()->second)mp.erase(--mp.end());
		}mp[a[i+1].c]+=ad;
	}return cost;
}
int main()
{
	int T=read();while(T--)
	{
		n=read();m=read();c=read();c0=read();
		for(int i=1;i<=n;i++)a[i].t=read(),a[i].o=read(),a[i].c=read();
		a[++n]=node(0,m,0);sort(a+1,a+1+n,cmp);
		pr2(solve());
	}
	return 0;
}