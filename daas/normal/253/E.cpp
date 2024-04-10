#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<queue>
#define ll long long
#define int long long
using namespace std;
const int MAXN=5e4+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,num[MAXN];
struct data
{
	int st,len,p,id;
}ins[MAXN];
inline int cmpp(data x,data y) {return x.p<y.p;}
inline int cmps(data x,data y) {return x.st<y.st;}
struct Data
{
	int id,P,val;
	Data(int _id=0,int _P=0,int _val=0) {id=_id,P=_P,val=_val;}
	bool operator <(const Data &Z) const {return P<Z.P;}
};
priority_queue<Data> Q;
int ans[MAXN];
void check()
{
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		int len=ins[l].st-ins[l-1].st,cur=ins[l-1].st;
		while(len && !Q.empty())
		{
			Data u=Q.top();
			Q.pop();
			int minn=min(u.val,len);
			cur+=minn;
			len-=minn;
			u.val-=minn;
			if(u.val) Q.push(u);
			else ans[u.id]=cur;
		}
		while(r+1<=n && ins[r+1].st==ins[l].st) ++r;
		for(int i=l;i<=r;++i) Q.push(Data(ins[i].id,ins[i].p,ins[i].len));
	}
	int len=0x3f3f3f3f3f3f3f3f,cur=ins[n].st;
	while(len && !Q.empty())
	{
		Data u=Q.top();
		Q.pop();
		int minn=min(u.val,len);
		cur+=minn;
		len-=minn;
		u.val-=minn;
		if(u.val) Q.push(u);
		else ans[u.id]=cur;
	}
}
signed main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) ins[i].st=read(),ins[i].len=read(),ins[i].p=read(),ins[i].id=i;
	sort(ins+1,ins+n+1,cmpp);
	if(ins[2].p!=1) num[++num[0]]=1;
	for(int i=2;i<=n;++i) if(ins[i].p!=ins[i+1].p && ins[i].p+1!=ins[i+1].p) num[++num[0]]=ins[i].p+1;
	sort(num+1,num+num[0]+1);
	num[0]=unique(num+1,num+num[0]+1)-num-1;
	sort(ins+1,ins+n+1,cmps);
	int l=1,r=num[0],ANS=0,bj=1,lim=read();
	while(ins[bj].p!=-1) ++bj;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		ins[bj].p=num[mid];
		check();
		if(ans[ins[bj].id]<=lim) ANS=num[mid],r=mid-1;
		else l=mid+1;
	}
	ins[bj].p=ANS;
	check();
	printf("%lld\n",ANS);
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
	putchar('\n');
	return 0;
}
//ore no turn,draw