#include<bits/stdc++.h>
#define maxn 200005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
inline void read(int &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
inline void print(int x) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10);putchar(x%10+'0');
}
int n,m;
bool d[maxn];
int pos[maxn];
int dri[maxn],lend;
int gue[maxn],leng;
int ans[maxn];
int crabby_bound(int x)
{
	int l=0,r=m-1;
	if(x<dri[0]) return 0;
	if(x>dri[r]) return r;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(x==dri[mid]) return  mid;
		else if(x>dri[mid]) l=mid;
		else r=mid;
	}
	if(x-dri[l]<=dri[r]-x) return l;
	return r;
}
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n+m;i++) cin>>pos[i];
	for(i=1;i<=n+m;i++) cin>>d[i];
	for(i=1;i<=n+m;i++)
	{
		if(d[i]==1) dri[lend++]=pos[i];
		else gue[leng++]=pos[i];
	}
	sort(dri,dri+m);
	for(i=0;i<n;i++)
		ans[crabby_bound(gue[i])]++;
	for(i=0;i<m;i++) cout<<ans[i]<<" ";
	return 0;
}