#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define pii pair<int,int>
#define fi first
#define se second
const int N=2e5+7;
struct Query{
	int op,x,y;	
}q[N];
int n,m,Q,lshx[N],lshy[N];
namespace T{
	set<pii>t[N];
	#define lb(x) ((x)&-(x))
	inline void add(int x,int y,int op){
		int p=m-y+1;
		for(;p<=m;p+=lb(p)){
			if(!op)t[p].insert(pii(x,y));
			else t[p].erase(pii(x,y));
		}
	}
	inline pii query(int x,int y){
		int p=m-y+1;pii D=pii(x,y),res=pii(n+1,m+1);
		for(;p;p-=lb(p)){
			auto it=t[p].lower_bound(D);
			if(it!=t[p].end())res=min(res,*it);
		}
		return res;
	}
}
char str[7];
int main(){
	Q=read();
	for(int i=1;i<=Q;i++){
		scanf("%s",str),q[i].x=read(),q[i].y=read();
		if(str[0]=='a')q[i].op=0;
		else if(str[0]=='r')q[i].op=1;
		else q[i].op=2,q[i].x++,q[i].y++;
		lshx[i]=q[i].x,lshy[i]=q[i].y;
	}
	sort(lshx+1,lshx+Q+1),n=unique(lshx+1,lshx+Q+1)-lshx-1;
	sort(lshy+1,lshy+Q+1),m=unique(lshy+1,lshy+Q+1)-lshy-1;
	for(int i=1;i<=Q;i++){
		q[i].x=lower_bound(lshx+1,lshx+n+1,q[i].x)-lshx;
		q[i].y=lower_bound(lshy+1,lshy+m+1,q[i].y)-lshy;
	}
	for(int i=1;i<=Q;i++){
		if(q[i].op<2){T::add(q[i].x,q[i].y,q[i].op);continue;}
		pii ans=T::query(q[i].x,q[i].y);
		if(ans.fi==n+1)puts("-1");
		else printf("%d %d\n",lshx[ans.fi],lshy[ans.se]);	
	}
	return 0;	
}