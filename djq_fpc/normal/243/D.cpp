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
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
const int inf=0x3f3f3f3f;
int n,rtx,rty,i,j,dx,dy,pl[1005][1005],pr[1005][1005],px[1005][1005],mi[16000005],tag[16000005],x,a[1005][1005];
vector<int> allx,ally;
vector<pair<int,int> > v[1000005];
long long ans;
void upd(int x,int c)
{
	mi[x]=max(mi[x],c);
	tag[x]=max(tag[x],c);
}
void pushdo(int x)
{
	if(tag[x]){
		upd(x+x,tag[x]);
		upd(x+x+1,tag[x]);
		tag[x]=0;
	}
}
void update(int x,int l,int r,int ql,int qr,int c)
{
	if(ql<=l&&r<=qr){
		upd(x,c);return;
	}pushdo(x);int mid=(l+r)/2;
	if(ql<=mid)update(x+x,l,mid,ql,qr,c);
	if(qr>mid)update(x+x+1,mid+1,r,ql,qr,c);
	mi[x]=min(mi[x+x],mi[x+x+1]);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr){
		return mi[x];
	}pushdo(x);int mid=(l+r)/2,ans=inf;
	if(ql<=mid)ans=min(ans,query(x+x,l,mid,ql,qr));
	if(qr>mid)ans=min(ans,query(x+x+1,mid+1,r,ql,qr));
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&rtx,&rty);
	swap(rtx,rty);rtx*=-1;
	fz1(i,n)fz1(j,n){
		scanf("%d",&a[i][j]);
		if(a[i][j]){
			pl[i][j]=inf;pr[i][j]=-inf;px[i][j]=inf;
			fz0k(dx,2)fz0k(dy,2){
				int tx=rty*(i+dx)-rtx*(j+dy),ty=rtx*(i+dx)+rty*(j+dy);
				px[i][j]=min(px[i][j],tx);
				pl[i][j]=min(pl[i][j],ty);
				pr[i][j]=max(pr[i][j],ty);
			}
			allx.push_back(px[i][j]);
			ally.push_back(pl[i][j]);
			ally.push_back(pr[i][j]);
		}
	}
	sort(allx.begin(),allx.end());allx.resize(unique(allx.begin(),allx.end())-allx.begin());
	sort(ally.begin(),ally.end());ally.resize(unique(ally.begin(),ally.end())-ally.begin());
	fz1(i,n)fz1(j,n)if(a[i][j]){
		px[i][j]=upper_bound(allx.begin(),allx.end(),px[i][j])-allx.begin();
		pl[i][j]=upper_bound(ally.begin(),ally.end(),pl[i][j])-ally.begin();
		pr[i][j]=upper_bound(ally.begin(),ally.end(),pr[i][j]-1)-ally.begin();
		v[px[i][j]].push_back(make_pair(i,j));
	}
	fz1(i,allx.size()){
		ff(v[i],it){
			int t=query(1,1,ally.size(),pl[it->first][it->second],pr[it->first][it->second]);
			ans+=max(0,a[it->first][it->second]-t);
			update(1,1,ally.size(),pl[it->first][it->second],pr[it->first][it->second],a[it->first][it->second]);
		}
	}cout<<ans<<endl;
	return 0;
}