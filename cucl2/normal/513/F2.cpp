#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const long long Inf=0x3f3f3f3f3f3f3f3f;

namespace Flows{
	struct Edge{
		long long to,cap,rev;
		Edge(long long to,long long cap,long long rev):to(to),cap(cap),rev(rev){}
	};
	vector<Edge> egs[5005];
	bool lgl[5005];
	void NewEdge(long long u,long long v,long long cap){
		egs[u].push_back(Edge(v,cap,egs[v].size()));
		egs[v].push_back(Edge(u,0,egs[u].size()-1));
	}
	int dist[5005];
	long long calc(long long frm,long long to,long long cap){
		if(frm==to){
			//cerr<<' '<<frm<<' '<<cap<<endl;
			return cap;
		}
		lgl[frm]=1;
		long long ycap=cap;
		for(long long i=0;i<((long long)egs[frm].size());i++){
			if(egs[frm][i].cap&&dist[egs[frm][i].to]==dist[frm]+1){
				long long ff=calc(egs[frm][i].to,to,min(cap,egs[frm][i].cap));
				//if(ff){
					//cerr<<frm<<' '<<ff<<endl;
				cap-=ff;
				egs[frm][i].cap-=ff;
				egs[egs[frm][i].to][egs[frm][i].rev].cap+=ff;
				if(!cap){
					break;
				}
				//}
			}
		}
		if(cap==ycap){
			dist[frm]=-1;
		}
		//cerr<<"    "<<ycap<<' '<<cap<<endl;
		return ycap-cap;
	}
	bool bfs(int frm,int to){
		memset(dist,0x3f,sizeof(dist));
		queue<int> q;
		q.push(frm);
		dist[frm]=0;
		while(q.size()){
			int x=q.front();
			q.pop();
			for(int i=0;i<egs[x].size();i++){
				if(egs[x][i].cap&&dist[egs[x][i].to]==0x3f3f3f3f){
					q.push(egs[x][i].to);
					dist[egs[x][i].to]=dist[x]+1;
				}
			}
		}
		return dist[to]!=0x3f3f3f3f;
	}
	void init(){
		for(long long i=0;i<5005;i++){
			egs[i].clear();
		}
	}
}

struct prs{
	int r,c,t;
	//prs(long long r,long long c,long long t):r(r),c(c),t(t){}
};

int dist[25][25][25][25];
long long dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char s[25][25];
int n,m,boy,girl;
vector<prs> boys,girls;

bool valid(long long x,long long y){
	return x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]!='#';
}

void prebfs(long long x,long long y){
	queue<pair<long long,long long> > q;
	queue<int> b;
	q.push(make_pair(x,y));
	b.push(0);
	dist[x][y][x][y]=0;
	while(q.size()){
		pair<long long,long long> Q=q.front();
		int bs=b.front();
		q.pop();
		b.pop();
		for(long long i=0;i<4;i++){
			long long nx=Q.first+dx[i],ny=Q.second+dy[i];
			if(valid(nx,ny)&&dist[x][y][nx][ny]==0x3f3f3f3f){
				q.push(make_pair(nx,ny));
				b.push(bs+1);
				dist[x][y][nx][ny]=bs+1;
			}
		}
	}
}

bool check(long long M){
	Flows::init();
	for(long long i=0;i<((long long)boys.size());i++){
		Flows::NewEdge(0,i+1,1);
		for(long long j=1;j<=n;j++){
			for(long long k=1;k<=m;k++){
				if(dist[boys[i].r][boys[i].c][j][k]!=0x3f3f3f3f&&1LL*dist[boys[i].r][boys[i].c][j][k]*boys[i].t<=M){
					Flows::NewEdge(i+1,1000+j*m+k,1);
				}
			}
		}
	}
	for(long long j=1;j<=n;j++){
		for(long long k=1;k<=m;k++){
			Flows::NewEdge(1000+j*m+k,2000+j*m+k,1);
		}
	}
	for(long long i=0;i<((long long)girls.size());i++){
		Flows::NewEdge(3000+i,4000,1);
		for(long long j=1;j<=n;j++){
			for(long long k=1;k<=m;k++){
				if(dist[girls[i].r][girls[i].c][j][k]!=0x3f3f3f3f&&1LL*dist[girls[i].r][girls[i].c][j][k]*girls[i].t<=M){
					Flows::NewEdge(2000+j*m+k,3000+i,1);
				}
			}
		}
	}
	long long ans=0;
	while(Flows::bfs(0,4000)){
		memset(Flows::lgl,0,sizeof(Flows::lgl));
		long long ff=Flows::calc(0,4000,Inf);
		if(!ff){
			break;
		}
		ans+=ff;
	}
	//cerr<<ans<<' '<<boys.size()<<endl;
	return ans==(long long)boys.size();
}
//boynextdoor
int main(){
	scanf("%d%d%d%d",&n,&m,&boy,&girl);
	for(long long i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	if(abs(boy-girl)!=1){
		puts("-1\n");
		return 0;
	}
	prs boss;
	scanf("%d%d%d",&boss.r,&boss.c,&boss.t);
	if(boy<girl){
		boys.push_back(boss);
	}else{
		girls.push_back(boss);
	}
	for(long long i=0;i<boy;i++){
		scanf("%d%d%d",&boss.r,&boss.c,&boss.t);
		boys.push_back(boss);
	}
	for(long long i=0;i<girl;i++){
		scanf("%d%d%d",&boss.r,&boss.c,&boss.t);
		girls.push_back(boss);
	}
	memset((int*)dist,0x3f,sizeof(dist));
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			prebfs(i,j);
		}
	}
	long long l=-1,r=1e12;
	while(r-l>1){
		long long m=(l+r)>>1;
		if(check(m)){
			r=m;
		}else{
			l=m;
		}
		//cerr<<l<<' '<<m<<endl;
	}
	if(r==1e12){
		puts("-1");
		return 0;
	}
	#ifdef ORZDALAO
	printf("%lld\n",r);
	#else
	printf("%I64d\n",r);
	#endif
	return 0;
}