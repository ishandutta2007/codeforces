#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct data
{
	int a,b,c,d;
}p[100010],q[100010];
int n;
int ch[5000000][2],tot,rt;
bool ad[5000000],hv[5000000];
void pushdown(int k)
{
	if(!ch[k][0])ch[k][0]=++tot;
	hv[ch[k][0]]=1,ad[ch[k][0]]=1;
	if(!ch[k][1])ch[k][1]=++tot;
	hv[ch[k][1]]=1,ad[ch[k][1]]=1;
	ad[k]=0;
}
void ins(int &k,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)return;
	if(!k)k=++tot;
//	printf("%d %d %d %d %d\n",k,l,r,ll,rr);
	if(l>=ll&&r<=rr)
	{
		hv[k]=ad[k]=1;
		return;
	}
	if(ad[k])pushdown(k);
	ins(ch[k][0],l,l+r>>1,ll,rr);
	ins(ch[k][1],(l+r>>1)+1,r,ll,rr);
	hv[k]=hv[ch[k][0]]||hv[ch[k][1]];
}
bool query(int k,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll||!k)return 0;
//	printf("%d %d %d %d %d\n",k,l,r,ll,rr);
	if(l>=ll&&r<=rr)
	{
	//	printf("%d %d %d\n",l,r,hv[k]);
		return hv[k];
	}
	if(ad[k])pushdown(k);
	return query(ch[k][0],l,l+r>>1,ll,rr)||query(ch[k][1],(l+r>>1)+1,r,ll,rr);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d %d %d %d",&p[i].a,&p[i].b,&p[i].c,&p[i].d),q[i]=p[i];
	sort(p+1,p+1+n,[&](data a,data b){return a.c<b.c;});
	sort(q+1,q+1+n,[&](data a,data b){return a.d<b.d;});
//	for(int i=1;i<=n;++i)printf("%d %d %d %d\n",p[i].a,p[i].b,p[i].c,p[i].d);
//	for(int i=1;i<=n;++i)printf("%d %d %d %d\n",q[i].a,q[i].b,q[i].c,q[i].d);
	for(int i=1,last=1;i<=n;++i)
	{
		while(q[last].d<p[i].c)ins(rt,1,1000000000,q[last].a,q[last].b),++last;
//		printf("q %d %d\n",p[i].a,p[i].b);
		if(query(rt,1,1000000000,p[i].a,p[i].b))return printf("NO"),0;
	}
//	printf("!!!\n");
	for(int i=1;i<=tot;++i)ch[i][0]=ch[i][1]=hv[i]=ad[i]=0;
	tot=0;rt=0;
	sort(p+1,p+1+n,[&](data a,data b){return a.a<b.a;});
	sort(q+1,q+1+n,[&](data a,data b){return a.b<b.b;});
	for(int i=1,last=1;i<=n;++i)
	{
		while(q[last].b<p[i].a)ins(rt,1,1000000000,q[last].c,q[last].d),++last;
		if(query(rt,1,1000000000,p[i].c,p[i].d))return printf("NO"),0;
	}
	printf("YES");
	return 0;
}