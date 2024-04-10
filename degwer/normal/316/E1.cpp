#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define SIZE 262144
ll mod=1000000000;
typedef pair<ll,ll>pii;
ll fib[SIZE];
ll rui[SIZE];
void calc()
{
	rui[0]=0;
	fib[1]=1;
	fib[2]=1;
	rui[1]=1;
	rui[2]=2;
	for(int i=3;i<SIZE;i++)
	{
		fib[i]=(fib[i-1]+fib[i-2])%mod;
		rui[i]=(rui[i-1]+fib[i])%mod;
	}
}
class segtree
{
public:
	ll seg[SIZE*2];
	ll sub[SIZE*2];
	ll flag[SIZE*2];
	void update(int beg,int end,int node,int lb,int ub,ll num)
	{
		if(ub<beg||end<lb)
		{
			return;
		}
		if(beg<=lb&&ub<=end)
		{
			seg[node]+=(rui[ub-lb+1]*num)%mod;
			sub[node]+=(rui[ub-lb]*num)%mod;
			flag[node]=num;
			return;
		}
		if(flag[node])
		{
			flag[node*2]+=flag[node];
			flag[node*2+1]+=flag[node];
			seg[node*2]+=(flag[node]*(rui[(ub-lb+1)/2]))%mod;
			sub[node*2]+=(flag[node]*(rui[(ub-lb+1)/2-1]))%mod;
			seg[node*2+1]+=(flag[node]*(rui[(ub-lb+1)/2]))%mod;
			sub[node*2+1]+=(flag[node]*(rui[(ub-lb+1)/2-1]))%mod;
			flag[node]=0;
		}
		update(beg,end,node*2,lb,(lb+ub)/2,num);
		update(beg,end,node*2+1,(lb+ub)/2+1,ub,num);
		seg[node]=(seg[node*2]+seg[node*2+1]*fib[(ub-lb+1)/2+1]+sub[node*2+1]*fib[(ub-lb+1)/2])%mod;
		sub[node]=(sub[node*2]+seg[node*2+1]*fib[(ub-lb+1)/2]+sub[node*2+1]*fib[(ub-lb+1)/2-1])%mod;
	}
	pii get(int beg,int end,int node,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return make_pair(0,0);
		}
		if(beg<=lb&&ub<=end)
		{
			return make_pair(seg[node],sub[node]);
		}
		if(flag[node])
		{
			flag[node*2]+=flag[node];
			flag[node*2+1]+=flag[node];
			seg[node*2]+=(flag[node]*(rui[(ub-lb+1)/2]))%mod;
			sub[node*2]+=(flag[node]*(rui[(ub-lb+1)/2-1]))%mod;
			seg[node*2+1]+=(flag[node]*(rui[(ub-lb+1)/2]))%mod;
			sub[node*2+1]+=(flag[node]*(rui[(ub-lb+1)/2-1]))%mod;
			flag[node]=0;
		}
		pii a=get(beg,end,node*2,lb,(lb+ub)/2);
		pii b=get(beg,end,node*2+1,(lb+ub)/2+1,ub);
		pii ret;
		ret.first=(a.first+b.first*fib[min((ub-lb+1)/2,max(0,(ub+lb)/2+1-beg))+1]+b.second*fib[min((ub-lb+1)/2,max(0,(ub+lb)/2+1-beg))])%mod;
		ret.second=(a.second+b.first*fib[min((ub-lb+1)/2,max(0,(ub+lb)/2+1-beg))]+b.second*fib[min((ub-lb+1)/2,max(2,(ub+lb)/2+1-beg))-1])%mod;
		return ret;
	}
};
segtree tree;
int main()
{
	calc();
	int num,query;
	scanf("%d%d",&num,&query);
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		tree.update(i,i,1,0,SIZE-1,zan);
	}
	for(int i=0;i<query;i++)
	{
		int zan;
		scanf("%d",&zan);
		if(zan==1)
		{
			int za,zb;
			scanf("%d%d",&za,&zb);
			za--;
			tree.update(za,za,1,0,SIZE-1,zb-tree.get(za,za,1,0,SIZE-1).first);
		}
		if(zan==2)
		{
			int za,zb;
			scanf("%d%d",&za,&zb);
			za--;
			zb--;
			printf("%I64d\n",tree.get(za,zb,1,0,SIZE-1).first);
		}
		if(zan==3)
		{
			int za,zb,zc;
			scanf("%d%d%d",&za,&zb,&zc);
			za--;
			zb--;
			tree.update(za,zb,1,0,SIZE-1,zc);
		}
	}
}