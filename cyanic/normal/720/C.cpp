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

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
int xx[N],yy[N],yes[N],n,m,cnt,now,flag,x,y,X,Y,K,L=11;
vi a[N];

int calc(int x,int y){
	int res=0;
	res+=a[x-1][y-1]&a[x-1][y];
	res+=a[x-1][y-1]&a[x][y-1];
	res+=a[x-1][y]&a[x][y-1];
	res+=a[x-1][y]&a[x-1][y+1];
	return res;
}

int chk(int s){
	static int q[N];
	int l=0,r=0;
	rep(i,1,cnt){
		a[xx[i]][yy[i]]=0;
		yes[i]=0;
		if(!(s>>(i-1)&1)) continue;
		if(xx[i]==x||xx[i]==x+1&&yy[i]<=y) yes[i]=1,q[r++]=i;
	}
	while(l<r){
		int u=q[l++];
		rep(v,1,cnt)if(s>>(v-1)&1){
			if(!yes[v]&&abs(xx[u]-xx[v])+abs(yy[u]-yy[v])==1){
				yes[v]=1,q[r++]=v;
			}
		}
	}
	rep(i,1,cnt) if((s>>(i-1)&1)&&!yes[i]) return 0;
	int sum=now;
	rep(i,1,cnt) if(s>>(i-1)&1) sum+=calc(xx[i],yy[i]),a[xx[i]][yy[i]]=1;
	return sum==K;
}

void rmain(){
	read(n),read(m),read(K);
	if(n<m) swap(n,m),flag=1; else flag=0;
	rep(i,0,n+1) a[i].clear(),a[i].resize(m+2);
	now=0,x=n,y=m;
	int rem=n*m;
	rep(i,1,n){
		int owo=0;
		rep(j,1,m){
			int nxt=calc(i,j); rem--;
			if(now+nxt<=K&&rem>=L) now+=nxt,a[i][j]=1;
			else {x=i,y=j-1; if(y==0)y=m,x--; owo=1;break;}
		}
		if(owo) break;
	}
	cnt=0,X=x,Y=y;
	int Flag=(x<n);
	while(cnt+flag<L){
		Y++; if(Y>m) X++,Y=1;
		if(X>n) break;
		xx[++cnt]=X,yy[cnt]=Y;
		if(X==x+1&&Y==y) Flag=0;
	}
	if(Flag) xx[++cnt]=x+1,yy[cnt]=y;
	int found=0;
	for(int s=(x==0?1:0);s<(1<<cnt);s++)
		if(chk(s)){
			found=1;
			break;
		}
	if(!found){
		puts("-1");
		return;
	}
	if(flag) swap(n,m);
	rep(i,1,n){
		rep(j,1,m) printf("%c",(flag?a[j][i]:a[i][j])?'*':'.');
		puts("");
	}
}

int main(){
	int T; read(T);
	while(T--) rmain(),puts("");
	return 0;
}