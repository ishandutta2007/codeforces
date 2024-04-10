#include<bits/stdc++.h>
using namespace std;
#define N 500000
#define M 500000
#define QU 500000
#define QE 500000
#define mp make_pair
#define X first
#define Y second
void read(int &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
struct edge{int x,y,v;}eg[M+1];
inline bool operator<(edge &x,edge &y){return x.v<y.v;}
struct qedge{int x,y,v,id;}qeg[QE+1];
inline bool operator<(qedge &x,qedge &y){if(x.v!=y.v)return x.v<y.v;return x.id<y.id;}
int fa[N+1],rk[N+1];stack<pair<int,bool> > stk;
int ance(int x){return fa[x]==x?x:ance(fa[x]);}
inline bool merge(int x,int y){
	x=ance(x);y=ance(y);
	if(x==y)return false;
	if(rk[x]<rk[y])swap(x,y);
	bool mar=false;
	if(rk[x]==rk[y])rk[x]++,mar=true;
	fa[y]=x;stk.push(mp(y,mar));
	return true;
}
inline void cancel(){
	int x=stk.top().X;bool d=stk.top().Y;stk.pop();
	if(d)rk[fa[x]]--;fa[x]=x;
}
bitset<QU+1> yes;
int main(){
//	freopen("C:\\Users\\chenx\\OneDrive\\\\txt.txt","r",stdin);
//	int cl=clock();
	int n,m,qu,qe=0,cnt=1,i;read(n);read(m);
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++)read(eg[i].x),read(eg[i].y),read(eg[i].v);
	read(qu);
	for(i=1;i<=qu;i++){
		int x;read(x);
		while(x--){int y;read(y);qeg[++qe]=(qedge){eg[y].x,eg[y].y,eg[y].v,i};}
	}
//	cout<<clock()-cl<<"ms,finish reading\n";
	sort(eg+1,eg+m+1);sort(qeg+1,qeg+qe+1);
//	cout<<clock()-cl<<"ms,finish sorting edges\n";
//	puts("eg:");
//	for(i=1;i<=m;i++)printf("%d->%d:%d\n",eg[i].x,eg[i].y,eg[i].v);
//	puts("qeg:");
//	for(i=1;i<=qe;i++)printf("q#%d::%d->%d:%d\n",qeg[i].id,qeg[i].x,qeg[i].y,qeg[i].v);
	yes.set();
	int ed1=1;
	for(i=1;i<=qe;i=ed1){
		for(;cnt<=m&&eg[cnt].v<qeg[i].v;cnt++)merge(eg[cnt].x,eg[cnt].y);
		while(ed1<=qe&&qeg[ed1].v==qeg[i].v)ed1++;
//		printf("[%d,%d)\n",i,ed1);
		int ed2=i;
		for(int j=i;j<ed1;j=ed2){
			while(ed2<ed1&&qeg[ed2].id==qeg[j].id)ed2++;
//			printf("\t[%d,%d)\n",j,ed2);
			if(!yes[qeg[j].id])continue;
			int tm=0;
			for(int k=j;k<ed2;k++){
				if(!merge(qeg[k].x,qeg[k].y)){
//					printf("on qeg#%d,q#%d die\n",k,qeg[j].id);
					yes.reset(qeg[j].id);break;
				}
				tm++;
			}
			while(tm--)cancel();
		}
	}
	for(i=1;i<=qu;i++)puts(yes[i]?"YES":"NO");
//	cout<<clock()-cl<<"ms,finish";
	return 0;
}
/*1
5 7
1 2 2
1 3 2
2 3 1
2 4 1
3 4 1
3 5 2
4 5 2
4
2 3 4
3 3 4 5
2 1 7
2 1 2
*/