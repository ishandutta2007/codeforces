#include<cstdio>
#include<queue>
using namespace std;
const int o=2e5+10;
int T,n,a[o],m,b[o],lst[o];queue<int> q[o];
int main(){
	for(scanf("%d",&T);T--;m=0,putchar('\n')){
		scanf("%d",&n);
		for(int i=0;i<=n;++i) for(;!q[i].empty();q[i].pop());
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),q[a[i]].push(i);
		for(int r=0;r<n;) for(int i=0,t=r+1;1;++i){
			for(;!q[i].empty()&&q[i].front()<=r;q[i].pop());
			if(q[i].empty()){r=t;b[++m]=i;break;}
			t=max(t,q[i].front());
		}
		printf("%d\n",m);
		for(int i=1;i<=m;++i) printf("%d ",b[i]);
	}
	return 0;
}