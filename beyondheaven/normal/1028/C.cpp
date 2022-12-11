#include<bits/stdc++.h>
#define MaxN 150123
int n,s;
int x1[MaxN],y1[MaxN],x2[MaxN],y2[MaxN];
int b[MaxN<<2];
struct Operation
{
	int l,r,v;
	int y;
	Operation(int _l,int _r,int _v,int _y):
		l(_l),r(_r),v(_v),y(_y){}
	friend bool operator<(const Operation&lhs,const Operation&rhs)
	{
		return (lhs.y==rhs.y?lhs.v>rhs.v:lhs.y<rhs.y);
	}
};
std::vector<Operation>cmd;
inline void Init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
	for(int i=1;i<=n;++i)
	{
		b[++s]=x1[i];
		b[++s]=x2[i];
	}
	std::sort(b+1,b+s+1);
	s=std::unique(b+1,b+s+1)-b-1;
	for(int i=1;i<=n;++i)
	{
		int x1_rnk=std::lower_bound(b+1,b+s+1,x1[i])-b,
			x2_rnk=std::lower_bound(b+1,b+s+1,x2[i])-b;
		cmd.push_back(Operation(x1_rnk,x2_rnk,1,y1[i]));
		cmd.push_back(Operation(x1_rnk,x2_rnk,-1,y2[i]));
	}
	std::sort(cmd.begin(),cmd.end());
}
#define Mid ((L+R)>>1)
int maxv[MaxN<<4],tag[MaxN<<4];
inline void PushDown(int k)
{
	maxv[k<<1]+=tag[k];
	maxv[k<<1|1]+=tag[k];
	tag[k<<1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
inline void Modify(int l,int r,int v,int k=1,int L=1,int R=s)
{
	if(l<=L&&R<=r)
	{
		maxv[k]+=v;
		tag[k]+=v;
		return;
	}
	PushDown(k);
	if(l<=Mid)Modify(l,r,v,k<<1,L,Mid);
	if(Mid<r)Modify(l,r,v,k<<1|1,Mid+1,R);
	maxv[k]=std::max(maxv[k<<1],maxv[k<<1|1]);
}
int ansx;
inline void Print(int k=1,int L=1,int R=s)
{
	if(L==R)
	{
		if(maxv[k]>=n-1)
		ansx=b[L];
		return;
	}
	PushDown(k);
	Print(k<<1,L,Mid);Print(k<<1|1,Mid+1,R);
}
#undef Mid
inline void Solve()
{
	for(auto op:cmd)
	{
		Modify(op.l,op.r,op.v);
		if(maxv[1]>=n-1)
		{
			Print();
			printf("%d %d\n",ansx,op.y);
			return;
		}
	}
}
int main()
{
	Init();
	Solve();
	return 0;
}