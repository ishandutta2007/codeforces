#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 20000005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,q,ql,qr,qw,qk,lch[N],rch[N],mx[N],tot,ans,rt1,rt2;
map<int,int> mp;
char op[2];
void Query(int x,int L,int R)
{
	if(x==0) return;
	ans=max(ans,mx[x]);
	if(L==R) return;
	int mid=(L+R)>>1;
	if(qk<=mid)
		Query(lch[x],L,mid);
	else Query(rch[x],mid+1,R);
}

void Change(int &x,int L,int R)
{
	if(!x) x=++tot;
	if(ql<=L&&qr>=R)
	{
		mx[x]=max(mx[x],qw);
		return;
	}
	int mid=(L+R)>>1;
	if(ql<=mid)
		Change(lch[x],L,mid);
	if(qr>mid)
		Change(rch[x],mid+1,R);
}

int main()
{
	int t1,t2;
	cin>>n>>q;
	while(q--)
	{
		scanf("%d%d%s",&t1,&t2,op);
		if(mp[t1])
		{
			printf("0\n");
			continue;
		}
		mp[t1]=1;
		if(op[0]=='U')
		{
			ans=0;
			qk=t1;
			Query(rt2,1,n);
			printf("%d\n",t2-ans);
			ql=ans+1,qr=t2;
			if(ql<=qr)
			{
				qw=t1;
				Change(rt1,1,n);
			}
		}
		else
		{
			ans=0;
			qk=t2;
			Query(rt1,1,n);
			printf("%d\n",t1-ans);
			ql=ans+1;
			qr=t1;
			if(ql<=qr)
			{
				qw=t2;
				Change(rt2,1,n);
			}
		}
	}
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);