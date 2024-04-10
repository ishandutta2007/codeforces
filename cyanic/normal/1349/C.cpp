#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=1005,inf=1e9;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
struct node{
	int x,y,w;
	friend bool operator < (node a,node b){
		return a.w>b.w;
	}
}; priority_queue<node> q;
int a[N][N],f[N][N],vis[N][N],n,m,Q;
char st[N];

void push(int x,int y,int w){
	if(w<f[x][y]){
		f[x][y]=w;
		q.push((node){x,y,w});
	}
}

int main(){
	read(n),read(m),read(Q);
	rep(i,1,n){
		scanf("%s",st+1);
		rep(j,1,m){
			a[i][j]=st[j]-'0';
			f[i][j]=inf;
		}
	}
	rep(i,1,n){
		rep(j,1,m){
			REP(k,4){
				int xx=i+dx[k],yy=j+dy[k];
				if(xx<1||xx>n||yy<1||yy>m) continue;
				if(a[i][j]==a[xx][yy]){
					push(i,j,a[i][j]);
				}
			}
		}
	}
	for(;!q.empty();){
		int x=q.top().x,y=q.top().y;
		q.pop();
		if(vis[x][y]) continue;
		vis[x][y]=1;
		REP(k,4){
			int xx=x+dx[k],yy=y+dy[k];
			if(xx<1||xx>n||yy<1||yy>m) continue;
			int tim=(a[xx][yy]?f[x][y]+1:f[x][y]);
			if(a[xx][yy]) tim++;
			push(xx,yy,tim);
		}
	}
	while(Q--){
		int x,y; ll p;
		read(x),read(y),read(p);
		if(p<f[x][y]||f[x][y]>=inf){
			printf("%d\n",a[x][y]);
			continue;
		}
		printf("%d\n",int((p-f[x][y])&1));
	}
	return 0;
}