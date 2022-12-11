#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
struct point
{
	int x,y;
	friend bool operator < (point a,point b){return a.x<b.x;}
}p[3030];
int r,c,n,k,nxt[3030],lst[3030];
long long sum,ans;
set<int>s;
int S1,S2;
inline void ins(int y,int id)
{
	int z,cnt,mc,mc1,cnt1;
	auto S=clock();
	auto it=s.insert(y<<16|id).first;
	if(it!=s.begin())nxt[z=(*prev(it)&65535)]=id,lst[id]=z;
	if(next(it)!=s.end())lst[z=(*next(it)&65535)]=id,nxt[id]=z;
	S1+=clock()-S;S=clock();
	mc=id;cnt=0;
	for(int j=1;j<=k;++j)
	{
		if(nxt[mc])mc=nxt[mc];
		else ++cnt;
	}
	z=id;
	for(int j=1;j<=k;++j)
	{
		if(cnt)mc1=mc,cnt1=cnt-1;
		else mc1=lst[mc],cnt1=0;
		sum+=(p[z].y-p[lst[z]].y)*((cnt?(c+1):p[mc].y)-(cnt1?(c+1):p[mc1].y));
		cnt=cnt1,mc=mc1;z=lst[z];
	}
	S2+=clock()-S;
}
int main()
{
	p[0].y=0;
	scanf("%d %d %d %d",&r,&c,&n,&k);
	for(int i=1;i<=n;++i)scanf("%d %d",&p[i].x,&p[i].y);
	sort(p+1,p+1+n);
	int last=n;
	for(int i=r;i;--i)
	{
		while(p[last].x>i)--last;
		s.clear();memset(nxt,0,sizeof(nxt)),memset(lst,0,sizeof(lst));sum=0;
		int last1=last;
		for(int j=i;j;--j)
		{
			while(p[last1].x==j)ins(p[last1].y,last1),--last1;
			ans+=sum;
		}
	//	for(int j=1;j<=last;++j)ins(p[j].y,j);
	//	printf("%d %lld\n",i,sum);
	}
	printf("%lld",ans);
//	printf("\n%d %d\n",S1,S2);
	return 0;
}