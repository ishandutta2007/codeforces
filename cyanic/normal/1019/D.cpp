#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
 
const int N=2005;
struct OwO{int u,v;pii V;}owo[N*N];
int r[N],n,m;
pii p[N];
ll S;
 
inline ll cro(pii p,pii a,pii b){
	return 1ll*(a.x-p.x)*(b.y-p.y)
		 - 1ll*(a.y-p.y)*(b.x-p.x);
}
bool cmp(OwO a,OwO b){
	return cro(mp(0,0),a.V,b.V)>0;
}
 
int main(){
	cin>>n>>S,S*=2;
	rep(i,1,n)cin>>p[i].x>>p[i].y;
	sort(p+1,p+n+1);
	rep(i,1,n)r[i]=i;
	rep(i,1,n)rep(j,i+1,n)
		owo[++m]=(OwO){i,j,mp(p[j].x-p[i].x,p[j].y-p[i].y)};
	sort(owo+1,owo+m+1,cmp);
	rep(i,1,m){
		int &a=r[owo[i].u],&b=r[owo[i].v];
		int l=1,r=a-1,mid;
		while(l<r){
			mid=(l+r+1)>>1;
			if(abs(cro(p[a],p[b],p[mid]))>=S)l=mid;
			else r=mid-1;
		}
		if(abs(cro(p[a],p[b],p[l]))==S){
			printf("Yes\n%d %d\n%d %d\n%d %d\n",p[a].x,p[a].y,
							p[b].x,p[b].y,p[l].x,p[l].y);
			return 0;
		}
		swap(a,b),swap(p[a],p[b]);
	}
	puts("No");
	return 0;
}