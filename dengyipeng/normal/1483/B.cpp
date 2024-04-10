#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#define maxn 100005
using namespace std;

int T,n,i,j,k,a[maxn],pre[maxn],nex[maxn],bz[maxn],ans[maxn];
int gcd(int x,int y){return (x%y==0)?y:gcd(y,x%y);}
struct arr{int x,y;arr(int _x=0,int _y=0){x=_x,y=_y;}};
int operator<(arr a,arr b){return a.x<b.x||a.x==b.x&&a.y<b.y;}
set<arr> s;
set<arr> ::iterator it,it1;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) pre[i]=i-1,nex[i]=i+1;
		pre[1]=n,nex[n]=1,ans[0]=0;
		memset(bz,0,sizeof(int)*(n+1)),s.clear();
		for(i=1;i<=n;i++) if (gcd(a[i],a[nex[i]])==1)
			s.insert(arr(i,nex[i]));
		int now=1;
		while (!s.empty()){
			it=s.lower_bound(arr(now,0));
			while (it!=s.end()){
				if (!bz[(*it).x]&&!bz[(*it).y])
					break;
				it1=it,it1++;
				s.erase(it),it=it1;
			}
			if (it==s.end()){
				now=1;
				if (s.empty()) break;
				it=s.lower_bound(arr(now,0));
				while (it!=s.end()){
					if (!bz[(*it).x]&&!bz[(*it).y])
						break;
					it1=it,it1++;
					s.erase(it),it=it1;
				}
				if (it==s.end()) break;
			}
			int x=(*it).x,y=(*it).y;
			ans[++ans[0]]=y,bz[y]=1,now=nex[y];
			pre[nex[y]]=x,nex[x]=nex[y];
			if (gcd(a[x],a[nex[x]])==1)
				s.insert(arr(x,nex[x]));
		}
		printf("%d ",ans[0]);
		for(i=1;i<=ans[0];i++) printf("%d ",ans[i]);
		printf("\n");
	}
}