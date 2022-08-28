#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<iomanip>
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
#define y1 yyy
//#define T_ long long
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
int n,m,i,j,k,l,pre[255][255],sum[255];
string st[255];
long long hsh[555][2],mod[2]={1000000007ll,1000000009ll},ans,cnt,pw[35][2],pre2[255][255][2],syx[2]={-23333ll,-66666ll},len[555];
void manacher()
{
	long long i,l=0,r=0,ans=0;
	memset(len,0,sizeof(len));
	for (i=1;i<cnt;i++)
	{
		if (r>i) len[i]=min(len[2*l-i],r-i); else len[i]=1;
		while (hsh[i+len[i]][0]==hsh[i-len[i]][0]&&hsh[i+len[i]][1]==hsh[i-len[i]][1]) len[i]++;
		if (i+len[i]>r)
		{
			l=i;
			r=i+len[i];
		}
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	pw[0][0]=pw[0][1]=1;
	fz1(i,28)
	{
		fz0k(j,2)
		{
			pw[i][j]=pw[i-1][j]*257ll%mod[j];
		}
	}
	fz1(i,n)
	{
		rdst(st[i],255);
		st[i]=" "+st[i];
	}
	fz1(i,n)
	{
		fz1(j,m)
		{
			pre[i][j]=(pre[i][j-1]^(1<<(st[i][j]-'a')));
			fz0k(k,2) pre2[i][j][k]=(pre2[i][j-1][k]+pw[st[i][j]-'a'+1][k])%mod[k];
		}
	}
	fz1(i,m) fz(j,i,m)
	{
		long long fff=0;
		hsh[0][0]=-56655ll;
		hsh[0][1]=-15656ll;
		hsh[cnt=1][0]=syx[0];
		hsh[cnt=1][1]=syx[1];
		fz1(k,n)
		{
			int l;
			cnt++;
			if (__builtin_popcount(pre[k][j]^pre[k][i-1])<=1)
			{
				fz0k(l,2) hsh[cnt][l]=(pre2[k][j][l]-pre2[k][i-1][l]+mod[l])%mod[l];
			}
			else
			{
				hsh[cnt][0]=--fff;hsh[cnt][1]=-47799ll;
			}
			hsh[++cnt][0]=syx[0];
			hsh[cnt][1]=syx[1];
		}
		hsh[++cnt][0]=-56688ll;hsh[cnt][1]=-44999ll;
		manacher();
		fz1(k,cnt-1) if (hsh[k][0]>0||hsh[k][1]!=-47799ll) ans+=(len[k])/2;
	}
	cout<<ans<<endl;
	return 0;
}