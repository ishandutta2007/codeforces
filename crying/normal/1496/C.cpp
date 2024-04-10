#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int T,n,tot1,tot2;
db ans; 
struct Node{
	int x,y;
}a[MAXN],b[MAXN];
bool cmp1(const Node& n1,const Node& n2){
	return abs(n1.x)<abs(n2.x);
}
bool cmp2(const Node& n1,const Node& n2){
	return abs(n1.y)>abs(n2.y);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);tot1=tot2=0;
		rep(i,1,2*n){
			int x,y;
			scanf("%d%d",&x,&y);
			if(!x){
				a[++tot1]=(Node){x,y};
			}else{
				b[++tot2]=(Node){x,y};
			}
		}
		sort(a+1,a+1+n,cmp2);
		sort(b+1,b+1+n,cmp1);
		ans=0;
		rep(i,1,n){
			db dx=a[i].y,dy=b[n-i+1].x;
			ans+=sqrt(dx*dx+dy*dy);
		}
		printf("%.10f\n",ans);
	}
	return 0;
}