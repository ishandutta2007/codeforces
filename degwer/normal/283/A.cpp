#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define SIZE 262144
class segtree
{
public:
	ll seg[SIZE*2];
	ll flag[SIZE*2];
	void add(int beg,int end,int node,ll lb,ll ub,ll num)
	{
		if(ub<beg||end<lb)
		{
			return;
		}
		if(beg<=lb&&ub<=end)
		{
			seg[node]+=num*(ub-lb+1);
			flag[node]+=num;
			return;
		}
		if(flag[node])
		{
			seg[node*2]+=flag[node]*((ub-lb+1)/2);
			seg[node*2+1]+=flag[node]*((ub-lb+1)/2);
			flag[node*2]+=flag[node];
			flag[node*2+1]+=flag[node];
			flag[node]=0;
		}
		add(beg,end,node*2,lb,(lb+ub)/2,num);
		add(beg,end,node*2+1,(lb+ub)/2+1,ub,num);
		seg[node]=seg[node*2]+seg[node*2+1];
	}
	ll sum(int beg,int end,int node,ll lb,ll ub)
	{
		if(ub<beg||end<lb)
		{
			return 0;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[node];
		}
		if(flag[node])
		{
			seg[node*2]+=flag[node]*((ub-lb+1)/2);
			seg[node*2+1]+=flag[node]*((ub-lb+1)/2);
			flag[node*2]+=flag[node];
			flag[node*2+1]+=flag[node];
			flag[node]=0;
		}
		return sum(beg,end,node*2,lb,(lb+ub)/2)+sum(beg,end,node*2+1,(lb+ub)/2+1,ub);
	}
};
segtree tree;
int main()
{
	int num;
	scanf("%d",&num);
	int buf=1;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		if(zan==1)
		{
			int za,zb;
			scanf("%d%d",&za,&zb);
			za--;
			tree.add(0,za,1,0,SIZE-1,zb);
		}
		if(zan==2)
		{
			int za;
			scanf("%d",&za);
			tree.add(buf,buf,1,0,SIZE-1,za);
			buf++;
		}
		if(zan==3)
		{
			tree.add(buf-1,buf-1,1,0,SIZE-1,-tree.sum(buf-1,buf-1,1,0,SIZE-1));
			buf--;
		}
		printf("%lf\n",double(tree.sum(0,SIZE-1,1,0,SIZE-1))/double(buf));
	}
}