#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=(1<<12)|10;
const int SQRQ=(1<<8)|10;
const int DIVN=(1<<4)|10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,base=SQRQ,a[MAXN],pos[MAXN],mem[DIVN][SQRQ][SQRQ],ans[(1<<16)|10],cnt,step[2200010][2],id[MAXN];
int merge(int x,int y)
{
	if(!x) return y;
	if(!y) return x;
	step[++cnt][0]=x;
	step[cnt][1]=y;
	return cnt;
}
vector<int> A[DIVN];
int tmp[100][SQRQ][SQRQ],pre[SQRQ],suf[SQRQ],pcnt,rub[100];
int fun(int p,int l,int r)
{
	int x;
	if(rub[0])
	{
		x=rub[rub[0]--];
		memset(tmp[x],0,sizeof(tmp[x]));
	}
	else x=++pcnt;
	if(l==r)
	{
		for(int i=0;i<=id[l];++i)
			for(int j=id[l];j<A[p].size();++j)
				tmp[x][i][j]=pos[l];
		return x;
	}
	int mid=(l+r)>>1;
	int ls=fun(p,l,mid);
	int rs=fun(p,mid+1,r);
	memset(pre,-1,sizeof(pre));
	memset(suf,-1,sizeof(suf));
	for(int i=l;i<=r;++i) pre[id[i]]=suf[id[i]]=id[i];
	for(int i=1;i<A[p].size();++i) if(pre[i]==-1) pre[i]=pre[i-1];
	for(int i=A[p].size()-2;i>=0;--i) if(suf[i]==-1) suf[i]=suf[i+1];
	for(int i=A[p].size()-1;i>=0;--i)
		for(int j=i;j<A[p].size();++j)
		{
			if(suf[i]==i && pre[j]==j)
			{
				tmp[x][i][j]=merge(tmp[ls][i][j],tmp[rs][i][j]);
			}
			if(suf[i]!=-1 && pre[j]!=-1) tmp[x][i][j]=tmp[x][suf[i]][pre[j]];
		}
	rub[++rub[0]]=ls;
	rub[++rub[0]]=rs;
	return x;
}
int main()
{
	/*cout<<(sizeof(mem))/1024/1024<<endl;
	cout<<(sizeof(tmp)+sizeof(mem))/1024/1024<<endl;*/
	cnt=n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read(),pos[a[i]]=i;
	for(int p=1;p<=(n-1)/base+1;++p)
	{
		int l=(p-1)*base+1,r=min(n,p*base);
		for(int i=l;i<=r;++i) A[p].push_back(pos[i]);
		sort(A[p].begin(),A[p].end());
		for(int j=0;j<A[p].size();++j) id[a[A[p][j]]]=j;
		pcnt=rub[0]=0;
		memset(tmp,0,sizeof(tmp));
		fun(p,l,r);
		for(int i=0;i<A[p].size();++i)
			for(int j=i;j<A[p].size();++j)
				mem[p][i][j]=tmp[1][i][j];
	}
	/*cout<<endl;
	for(int p=1;p<=(n-1)/base+1;++p)
	{
		cout<<"cao "<<p<<endl;
		for(int i=0;i<A[p].size();++i) cout<<A[p][i]<<" ";
		cout<<endl;
		for(int i=0;i<A[p].size();++i)
			for(int j=i;j<A[p].size();++j)
				cout<<i<<" "<<j<<" "<<mem[p][i][j]<<endl;
	}
	cout<<"have "<<cnt-n<<endl;
	cout<<endl;*/
	for(int p=1;p<=q;++p)
	{
		int l=read(),r=read(),ANS=0;
		for(int i=1;i<=(n-1)/base+1;++i)
		{
			int L=0,R=A[i].size()-1,lim=-1,rim=-1;
			while(L<=R)
			{
				int mid=(L+R)/2;
				if(A[i][mid]>=l) lim=mid,R=mid-1;
				else L=mid+1;
			}
			L=0,R=A[i].size()-1;
			while(L<=R)
			{
				int mid=(L+R)/2;
				if(A[i][mid]<=r) rim=mid,L=mid+1;
				else R=mid-1;
			}
			if(lim==-1 || rim==-1) continue;
			ANS=merge(ANS,mem[i][lim][rim]);
		}
		ans[p]=ANS;
	}
	printf("%d\n",cnt);
	for(int i=n+1;i<=cnt;++i) printf("%d %d\n",step[i][0],step[i][1]);
	for(int i=1;i<=q;++i) printf("%d ",ans[i]);
	return 0;
}
//ore no turn,draw!