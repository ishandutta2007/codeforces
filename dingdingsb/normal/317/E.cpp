#include<bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define ppp pair<pii,pii>
#define L 0
#define R 1
#define D 2
#define U 3
#define vvx now.first.first
#define vvy now.first.second
#define ssx now.second.first
#define ssy now.second.second
#define mnx min(vvx,ssx)
#define mxx max(vvx,ssx)
#define mny min(vvy,ssy)
#define mxy max(vvy,ssy)
using namespace std;
int vx,vy,sx,sy,m;
int vis[450][450];
int flag[450][450];
int x[450],y[450];
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};
const char ch[4]={'L','R','D','U'};
bool In(int x,int y){return x>=5&&x<=440&&y>=5&&y<=440;}
bool Not(int x,int y){
	if(!In(x,y))return false;
	return vis[x][y];
}
bool fb(int x,int y){
	memset(flag,0,sizeof flag);
	queue<pii>q;q.push(mp(x,y));flag[x][y]=1;
	while(q.size()){
		auto [x,y]=q.front();q.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(!In(xx,yy))return false;
			if(vis[xx][yy])continue;
			if(flag[xx][yy])continue;
			flag[xx][yy]=1;
			q.push(mp(xx,yy));
		}
	}return true;
}
ppp work(ppp A,int dir){
	auto [x,y]=A.first;auto [xx,yy]=A.second;
	if(Not(x+dx[dir],y+dy[dir]))exit(-1);
	x+=dx[dir],y+=dy[dir];
	if(!Not(xx+dx[dir],yy+dy[dir]))xx+=dx[dir],yy+=dy[dir];
	putchar(ch[dir]);
	if(x==xx&&y==yy)exit(0);
	return mp(mp(x,y),mp(xx,yy));
} 
ppp work(ppp A,int dir,int times){
	while(times--)
		A=work(A,dir);
	return A;
}
ppp now;
void dfs(int x,int y){
	//printf("%d %d\n",x-210,y-210);
	if(flag[x][y]!=-10){
		int dir=flag[x][y]^1;
		dfs(x+dx[dir],y+dy[dir]);
	}else return;
	now=work(now,flag[x][y]);
}
signed main(){
	//freopen("1.out","w",stdout);
	scanf("%d%d%d%d%d",&vx,&vy,&sx,&sy,&m);
	if(!m){
		if(vx==sx&&vy==sy)return 0;
		return puts("-1"),0;
	}
	vx+=210,vy+=210,sx+=210,sy+=210;
	swap(vx,vy);swap(sx,sy);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&y[i],&x[i]);
		x[i]+=210;y[i]+=210;
		vis[x[i]][y[i]]=1;
	}
	bool V=fb(vx,vy);
	bool S=fb(sx,sy);
	if(V^S)
		return puts("-1"),0;
	if(V&&S){
		{
			memset(flag,0,sizeof flag);
			queue<pii>q;q.push(mp(vx,vy));flag[vx][vy]=0;
			while(q.size()){
				auto [x,y]=q.front();q.pop();
				for(int i=0;i<4;i++){
					int xx=x+dx[i],yy=y+dy[i];
					if(vis[xx][yy])continue;
					if(flag[xx][yy])continue;
					if(xx==sx&&yy==sy)
						goto loop;
					flag[xx][yy]=1;
					q.push(mp(xx,yy));
				}
			}
		}
		return puts("-1"),0;
		loop:;
		for(;;){
			memset(flag,0xff,sizeof flag);
			//flagdir 
			flag[vx][vy]=-10;
			queue<pii>q;q.push(mp(vx,vy));
			while(q.size()){
				auto [x,y]=q.front();q.pop();
				for(int i=0;i<4;i++){
					int xx=x+dx[i],yy=y+dy[i];
					if(vis[xx][yy])continue;
					if(flag[xx][yy]!=-1)continue;
					flag[xx][yy]=i;
					if(xx==sx&&yy==sy)
						goto out;
					q.push(mp(xx,yy));
				}
			}
			out:;
			now=mp(mp(vx,vy),mp(sx,sy));
			
			dfs(sx,sy);
			//putchar('\n');
			vx=now.first.first;
			vy=now.first.second;
			
			sx=now.second.first;
			sy=now.second.second;
			if(vx==sx&&vy==sy)
				return 0;
		}
	}
	memset(flag,0xff,sizeof flag);
	//flagdir 
	int ex,ey;
	flag[vx][vy]=-10;
	queue<pii>q;q.push(mp(vx,vy));
	while(q.size()){
		auto [x,y]=q.front();q.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(vis[xx][yy])continue;
			if(flag[xx][yy]!=-1)continue;
			flag[xx][yy]=i;
			if(!In(xx,yy)){
				ex=xx,ey=yy;
				goto out2;
			}
			q.push(mp(xx,yy));
		}
	}
	out2:;
	now=mp(mp(vx,vy),mp(sx,sy));
	dfs(ex,ey);
	
	if(ex==441)now=work(now,L,500),now=work(now,D,500);
	else now=work(now,D,500),now=work(now,L,500);
	now=work(now,D,500),now=work(now,L,500);
	
	sx=now.second.first;
	sy=now.second.second;
	if(In(sx,sy)){
		int ex,ey;
		memset(flag,0xff,sizeof flag);
		flag[sx][sy]=-10;
		while(q.size())q.pop();
		q.push(mp(sx,sy));
		while(q.size()){
			auto [x,y]=q.front();q.pop();
			for(int i=0;i<4;i++){
				int xx=x+dx[i],yy=y+dy[i];
				if(vis[xx][yy])continue;
				if(flag[xx][yy]!=-1)continue;
				flag[xx][yy]=i;
				if(!In(xx,yy)){
					ex=xx,ey=yy;
					goto out3;
				}
				q.push(mp(xx,yy));
			}
		}
		out3:;
		dfs(ex,ey);
		
		if(ex==441)now=work(now,L,500),now=work(now,D,500);
		else now=work(now,D,500),now=work(now,L,500);
	}
	if(ssx>=vvx&&ssy>=vvy){
		int mn=0x3f3f3f3f;
		for(int i=1;i<=m;i++)mn=min(mn,x[i]);
		while(ssx!=mn)
			now=work(now,U);
		while(!Not(ssx+dx[R],ssy+dy[R]))
			now=work(now,R);
		while(vvy!=ssy)
			now=work(now,R);
		now=work(now,D);
		now=work(now,R);
		while(1)now=work(now,U);
	}
	if(ssx>=vvx&&ssy<=vvy){
		while(ssy<=440)now=work(now,R);
		int mn=0x3f3f3f3f;
		for(int i=1;i<=m;i++)mn=min(mn,x[i]);
		while(ssx!=mn)
			now=work(now,U);
		while(!Not(ssx+dx[L],ssy+dy[L]))
			now=work(now,L);
		while(vvy!=ssy)
			now=work(now,L);
		now=work(now,D);
		now=work(now,L);
		while(1)now=work(now,U);
	}
	if(ssx<=vvx&&ssy<=vvy){
		while(ssy<=440)now=work(now,R);
		int mx=-0x3f3f3f3f;
		for(int i=1;i<=m;i++)mx=max(mx,x[i]);
		while(ssx!=mx)
			now=work(now,U);
		while(!Not(ssx+dx[L],ssy+dy[L]))
			now=work(now,L);
		while(vvy!=ssy)
			now=work(now,L);
		now=work(now,U);
		now=work(now,L);
		while(1)now=work(now,D);
	}
	if(ssx<=vvx&&ssy>=vvy){
		int mx=-0x3f3f3f3f;
		for(int i=1;i<=m;i++)mx=max(mx,x[i]);
		while(ssx!=mx)
			now=work(now,U);
		while(!Not(ssx+dx[R],ssy+dy[R]))
			now=work(now,R);
		while(vvy!=ssy)
			now=work(now,R);
		now=work(now,U);
		now=work(now,R);
		while(1)now=work(now,D);
	}
}