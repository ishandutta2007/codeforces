#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cassert>
#include<set>
#include<iomanip>
#include<ctime>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
int n,m,i,j,a[100005],np[100005];
vector<int> p,f;
int excgcd(int n,int m,int &x,int &y)
{
	if (m==0)
	{
		x=1;
		y=0;
		return n;
	}
	int ans=excgcd(m,n%m,y,x);
	y=y-n/m*x;
	return ans;
}
int main()
{
	srand(time(NULL));
	for (i=2;i<=100000;i++)
	{
		if (!np[i])
		{
			p.push_back(i);
			for (j=i+i;j<=100000;j+=i)
			{
				np[j]=1;
			}
		}
	}
	scanf("%d",&n);
	int t=n;
	for (i=0;i<p.size()&&sqr(p[i])<=t;i++)
	{
		while (t%p[i]==0)
		{
			f.push_back(p[i]);
			t/=p[i]; 
		}
	}
	if (t>1) f.push_back(t);
	sort(f.begin(),f.end());
	f.resize(unique(f.begin(),f.end())-f.begin());
	if (f.size()<2)
	{
		puts("NO");
		return 0;
	}
	for (;;)
	{
		random_shuffle(f.begin(),f.end());
		int x=f[0],y=f[1],xx,yy;
		excgcd(x,y,xx,yy);
		xx*=-1;yy*=-1;
		xx+=n/x;
		while (xx<0){xx+=n/x;yy-=n/y;}
		while (yy<0){xx-=n/x;yy+=n/y;}
		if (xx>=0&&yy>=0)
		{
			vector<int> s1,s2;
			if (xx>0)
			{
				s1.push_back(xx);
				s2.push_back(n/x);
			}
			if (yy>0)
			{
				s1.push_back(yy);
				s2.push_back(n/y);
			}
			cout<<"YES\n";
			cout<<s1.size()<<endl;
			for (i=0;i<s1.size();i++)
			{
				cout<<s1[i]<<' '<<s2[i]<<endl;
			}
			return 0;
		}
	}
	return 0;
}