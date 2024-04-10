#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,sz,q;
pair<int,int> tp[200111];
int a[200111],sa[200111],nsa[200111],rk[200111],nrk[200111],b[200111];
int lcp[200111],tab[20][200111];
void makeb()
{
	memset(b,0,sizeof(b));
	for(int i=1;i<=sz;i++)b[rk[i]]++;
	for(int i=1;i<=sz;i++)b[i]+=b[i-1];
}
#define usb(x) MP(rk[x],x+k>sz?-1:rk[x+k])
void construct_sa()
{
	for(int i=1;i<=sz;i++)tp[i]=MP(a[i],i);
	sort(tp+1,tp+sz+1);
	for(int i=1;i<=sz;i++)sa[i]=tp[i].SS;
	rk[sa[1]]=0;
	for(int i=2;i<=sz;i++)rk[sa[i]]=rk[sa[i-1]]+(a[sa[i-1]]<a[sa[i]]);
	for(int k=1;k<sz;k<<=1)
	{
		makeb();
		for(int i=sz;i>0;i--)if(sa[i]>k)nsa[b[rk[sa[i]-k]]--]=sa[i]-k;
		for(int i=sz;i>0;i--)if(sa[i]>sz-k)nsa[b[rk[sa[i]]]--]=sa[i];
		nrk[nsa[1]]=1;
		for(int i=2;i<=sz;i++)nrk[nsa[i]]=nrk[nsa[i-1]]+(usb(nsa[i-1])<usb(nsa[i]));
		swap(rk,nrk);
		swap(sa,nsa);
	}
	for(int i=1;i<=sz;i++)rk[sa[i]]=i;
	int h=0;
	for(int i=1;i<=sz;i++)
	{
		if(h>0)h--;
		if(rk[i]==1)continue;
		int j=sa[rk[i]-1];
		while(i+h<=sz&&j+h<=sz&&a[i+h]==a[j+h])h++;
		lcp[rk[i]-1]=h;
	}
	for(int i=1;i<sz;i++)tab[0][i]=lcp[i];
	for(int i=1;i<20;i++)
	{
		for(int j=1;j<=sz-(1<<i);j++)
		{
			tab[i][j]=min(tab[i-1][j],tab[i-1][j+(1<<(i-1))]);
		}
	}
}
int bisearchl(int x,int len)
{
	int pos=x;
	for(int i=19;i>=0;i--)
	{
		if((pos-(1<<i))>0&&tab[i][pos-(1<<i)]>=len)
		{
			pos-=(1<<i);
		}
	}
	return pos;
}
int bisearchr(int x,int len)
{
	int pos=x;
	for(int i=19;i>=0;i--)
	{
		if(tab[i][pos]>=len)
		{
			pos+=(1<<i);
		}
	}
	return pos;
}
vector<pair<pair<int,int>,int> >cmd[200111];
int ans[100111];
void query(int x,int y,int id)
{
	int l=bisearchl(rk[x+n+1],y-x+1);
	int r=bisearchr(rk[x+n+1],y-x+1);
//	cout<<l<<","<<r<<endl;
	pair<int,int> p=MP(max(0,x-(y-x+1)-1),y+1);
	cmd[r].PB(MP(p,id));
	cmd[l-1].PB(MP(p,-id));
}
struct BIT
{
	int a[200111];
	BIT(){memset(a,0,sizeof(a));}
	void add(int x)
	{
		for(;x<200111;x+=x&(-x))a[x]++;
	}
	int sum(int x)
	{
		int ans=0;
		for(;x>0;x-=x&(-x))ans+=a[x];
		return ans;
	}
}kotori;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	n--;sz=n*2+1;
	for(int i=1;i<=n;i++)a[i]-=a[i+1];
	a[n+1]=2147483647;
	for(int i=1;i<=n;i++)a[i+n+1]=-a[i];
//	for(int i=1;i<=sz;i++)cout<<a[i]<<" ";cout<<endl;
	construct_sa();
/*	for(int i=1;i<=sz;i++)
	{
		for(int j=sa[i];j<=sz;j++)cout<<a[j]<<" ";
		cout<<"lcp:"<<lcp[i];cout<<endl;
	}*/
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)ans[i]=n;
		else query(x,y-1,i);
	}
	int tot=0;
	for(int i=1;i<=sz;i++)
	{
		if(sa[i]<=n)kotori.add(sa[i]),tot++;
		for(int j=0;j<cmd[i].size();j++)
		{
			int x=cmd[i][j].SS;
			int coef=1;
			if(x<0)coef=-1,x=-x;
			pair<int,int> p=cmd[i][j].FF;
			int val=tot-kotori.sum(p.SS)+kotori.sum(p.FF);
			ans[x]+=coef*val;
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}