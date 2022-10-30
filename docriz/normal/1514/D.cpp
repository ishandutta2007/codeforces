#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int x,cnt;
	node(int nx=0,int ncnt=0)
	{
		x=nx;cnt=ncnt;
	};
	bool operator<(const node&y)const
	{
		return x<y.x;
	}
}tr[1200005],ans;
int n,a[300005],q,l,r,x,cnt[300005],gl,gr;
vector<int>pos[300005];
int query(int p,int l,int r){return upper_bound(pos[p].begin(),pos[p].end(),r)-lower_bound(pos[p].begin(),pos[p].end(),l);}
node mrg(node a,node b,int l,int r)
{
	int tmp;
	node nw;
	if(a.x!=-1&&2*(tmp=query(a.x,l,r))>r-l+1)return node(a.x,tmp);
	if(b.x!=-1&&2*(tmp=query(b.x,l,r))>r-l+1)return node(b.x,tmp);
	return node(-1,0);
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		tr[p]=node(a[l],1);
		return;
	}
	int mid=(l+r)/2;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	tr[p]=mrg(tr[2*p],tr[2*p+1],l,r);
}
void ask(int p,int l,int r)
{
	int tmp;
	if(gl>r||gr<l)return;
	if(l>=gl&&r<=gr)
	{
		if(tr[p].x!=-1&&2*(tmp=query(tr[p].x,gl,gr))>gr-gl+1)ans=node(tr[p].x,tmp);
		return;
	}
	int mid=(l+r)/2;
	ask(2*p,l,mid);
	ask(2*p+1,mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[i]=x;
		cnt[x]++;
		pos[x].push_back(i);
	}
	for(int i=1;i<=n;i++)pos[i].push_back(n+1);
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);gl=l;gr=r;
		ans=node(-1,0);
		ask(1,1,n);
		if(ans.x==-1)printf("1\n");
		else
		{
			int xj=gr-gl+1-ans.cnt;
			printf("%d\n",ans.cnt-xj);
		}
	}
	return 0;
}