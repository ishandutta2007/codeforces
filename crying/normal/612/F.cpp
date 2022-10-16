#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2010,INF=1e8;
int n,s,a[MAXN],b[MAXN],tot;
int f[MAXN],g[MAXN],state[MAXN];
int cost[MAXN][MAXN];
vector<int>pos[MAXN];
il ll normaldist(int i,int j){
	// 
	if(j>=i)return abs(i-j);
	else return n-abs(i-j); 
}
il ll reversedist(int i,int j){
	// 
	if(j<=i)return abs(i-j);
	else return n-abs(i-j);
}
il ll dist(int i,int j){
	return Min(normaldist(i,j),reversedist(i,j));
}
void solve(int lvl,int st,int ed){
	//lvlsted
	if(lvl==1){
		//sst
		if(normaldist(s,st)<=reversedist(s,st)){
			// 
			printf("+%d\n",normaldist(s,st));
		}else{
			// 
			printf("-%d\n",reversedist(s,st));
		}
	}else{
		//sted
		int lst=0,led=0; 
		int sz2=pos[lvl-1].size();
		rep(j,0,sz2-1){
			if(g[pos[lvl-1][j]]+dist(pos[lvl-1][j],st)==f[st]){
				led=pos[lvl-1][j];break;
			}
		}
		lst=led;
		rep(j,0,sz2-1){if(pos[lvl-1][j]==led)continue;
			if(f[pos[lvl-1][j]]+cost[pos[lvl-1][j]][led]==g[led]){
				lst=pos[lvl-1][j];break;
			}
		}
		solve(lvl-1,lst,led);
		//ledst
		if(normaldist(led,st)<=reversedist(led,st)){
			// 
			printf("+%d\n",normaldist(led,st));
		}else{
			// 
			printf("-%d\n",reversedist(led,st));
		}
	}
	//sted
	int sz=pos[lvl].size();
	if(sz==1)return; //
	if(sz==2){
		if(normaldist(st,ed)<=reversedist(st,ed)){
			// 
			printf("+%d\n",normaldist(st,ed));
		}else{
			// 
			printf("-%d\n",reversedist(st,ed));
		}
		return;
	} 
	int now=state[ed];
	int prev=pos[lvl][(now-1+sz)%sz];
	int nxt=pos[lvl][(now+1)%sz];
	now=ed;
	if(reversedist(st,nxt)+normaldist(nxt,now)<=normaldist(st,prev)+reversedist(prev,now)){
		//ed 
		int idx=state[st],flag=0;
		while(idx!=state[nxt]){
			printf("-%d\n",reversedist(pos[lvl][idx],pos[lvl][(idx-1+sz)%sz]));
			idx=(idx-1+sz)%sz;
		} 
		int cnt=0;
		while(idx!=state[now]){
			if(idx==state[st])flag=1;
			if(flag)printf("+%d\n",normaldist(cnt?pos[lvl][idx]:nxt,pos[lvl][(idx+1)%sz]));
			if(flag)cnt++;
			idx=(idx+1)%sz;
		}
		
	}else{
		//ed 
		int idx=state[st],flag=0;
		while(idx!=state[prev]){
			printf("+%d\n",normaldist(pos[lvl][idx],pos[lvl][(idx+1)%sz]));
			idx=(idx+1)%sz;
		} 
		int cnt=0;
		while(idx!=state[now]){
			if(idx==state[st])flag=1;
			if(flag)printf("-%d\n",reversedist(cnt?pos[lvl][idx]:prev,pos[lvl][(idx-1+sz)%sz]));
			if(flag)cnt++;
			idx=(idx-1+sz)%sz;
		}
		
	}
}
int main(){
	cin>>n>>s;
	rep(i,1,n){
		cin>>a[i];b[i]=a[i];
	}
	sort(b+1,b+1+n);tot=unique(b+1,b+1+n)-b-1;
	rep(i,1,n){
		a[i]=lower_bound(b+1,b+1+tot,a[i])-b;
		pos[a[i]].pb(i);
		state[i]=pos[a[i]].size()-1;
	}
	rep(i,1,n)f[i]=g[i]=INF;
	//cost
	rep(i,1,n){
		rep(j,1,n){
			if(a[i]!=a[j])continue;
			if(i==j)continue;
			int sz=pos[a[j]].size();
			if(sz==2){
				//
				cost[i][j]=dist(i,j);
				continue; 
			}
			int now=state[j];
			int prev=pos[a[j]][(now-1+sz)%sz];
			int nxt=pos[a[j]][(now+1)%sz];
			now=j;
			//prev-now-nxt
			cost[i][j]=Min(reversedist(i,nxt)+normaldist(nxt,now),
			normaldist(i,prev)+reversedist(prev,now));
		}
	} 
	rep(i,1,n){
		if(a[i]!=1)continue;
		f[i]=dist(s,i);
	}
	rep(i,1,tot){
		//g
		int sz=pos[i].size();
		rep(from,0,sz-1){
			rep(to,0,sz-1){if(from==to)continue;
				int st=pos[i][from],ed=pos[i][to]; 
				g[ed]=Min(g[ed],f[st]+cost[st][ed]);
			}
		}
		if(sz==1){ // 
			int only=pos[i][0];
			g[only]=f[only];
		} 
		//f
		if(i==n)break;
		int sz2=pos[i+1].size();
		rep(from,0,sz-1){
			rep(to,0,sz2-1){
				int st=pos[i][from],ed=pos[i+1][to];
				f[ed]=Min(f[ed],g[st]+dist(st,ed));			
			}
		} 
	}
	int ans=INF,st,ed;
	rep(i,1,n){
		if(a[i]!=tot)continue;
		if(g[i]<ans){
			ed=i;
		}
		ans=Min(ans,g[i]);
	}
	st=ed;
	int sz=pos[tot].size();
	rep(j,0,sz-1){
		int u=pos[tot][j];if(u==ed)continue;
		if(f[u]+cost[u][ed]==g[ed]){
			st=u;
			break;
		}
	}
	cout<<ans<<endl;
	solve(tot,st,ed);
	return 0;
}
/*
50 32
36 6 13 27 44 28 4 17 26 24 18 46 8 39 32 5 23 33 11 1 22 43 41 12 47 48 47 21 49 7 45 9 42 16 35 40 19 34 31 10 37 25 15 3 38 29 30 20 2 14
*/