#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
long long n,m,t,k,i,j,s[3005],x,y,l[3005],r[3005],to[3005],val[3005],ans,tmp;
vector<long long> pos[3005];
void ins(long long &x,long long y)
{
	r[x]=y;l[y]=x;x=y;
}
void shan(long long x)
{
	l[r[x]]=l[x];r[l[x]]=r[x];
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&t,&k);
	fz1(i,t){
		scanf("%I64d%I64d",&x,&y);pos[x].push_back(y);
	}
	fz1(i,n){
		fz(j,i,n) ff(pos[j],it) s[*it]++;
		tmp=0;long long lst=0;
		fz1(j,m) if (s[j]) ins(lst,j);ins(lst,m+1);
		long long p=0,sum=0;
		for (j=r[0];j<=m;j=r[j]){
			while (sum<k&&p<=m){
				p=r[p];sum+=s[p];
			}
			tmp+=(j-l[j])*(m-p+1);
			to[j]=p;val[j]=sum;
			sum-=s[j];
		}
		fd(j,n,i){
			ans+=tmp;
			ff(pos[j],it){
				s[*it]--;long long p=*it,sum=0;
				while (p&&sum+s[l[p]]<k){
					p=l[p];sum+=s[p];
				}
				while (p<=*it){
					if ((--val[p])<k&&to[p]<=m){
						tmp-=(p-l[p])*(r[to[p]]-to[p]);
						to[p]=r[to[p]];val[p]+=s[to[p]];
					}p=r[p];
				}
				if (!s[*it]) shan(*it);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}