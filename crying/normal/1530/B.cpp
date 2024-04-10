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
const int next_x[8]={-1,-1,-1,0,1,1,1,0},next_y[8]={-1,0,1,1,1,0,-1,-1};
int T,n,m,ans;
int tag[30][30],tag2[30][30];
int a,b;
int valid(int x,int y,int tag[][30]){
	if(x<1 || x>n || y<1 || y>m)return 0;
	rep(k,0,7){
		int cx=x+next_x[k],cy=y+next_y[k];
		if(tag[cx][cy])return 0;
	}
	return 1;
}
void solve(int x,int y,int cnt,int tag[][30]){
//	printf("(%d,%d)\n",x,y);
	if(x==1){
		if(y==m)tag[2][m]=valid(2,m,tag);
		if(y==m)solve(2,m,cnt+tag[2][m],tag);
		if(y!=m)tag[x][y+1]=valid(x,y+1,tag);
		if(y!=m)solve(x,y+1,cnt+tag[x][y+1],tag);
		return;
	}
	if(y==m){
		if(x==n){
			tag[n][m-1]=valid(n,m-1,tag);
			solve(n,m-1,cnt+tag[n][m-1],tag);
		}else{
			tag[x+1][m]=valid(x+1,m,tag);
			solve(x+1,m,cnt+tag[x+1][m],tag);
		}
		return;
	}
	if(x==n){
		if(y==1){
			tag[n-1][1]=valid(n-1,1,tag);
			solve(n-1,1,cnt+tag[n-1][1],tag);
		}else{
			tag[n][y-1]=valid(n,y-1,tag);
			solve(n,y-1,cnt+tag[n][y-1],tag);
		}
		return;
	}
	if(y==1){
		if(x==1){
			return;
		}else{
			if(x==2)return;
			tag[x-1][y]=valid(x-1,y,tag);
			solve(x-1,y,cnt+tag[x-1][y],tag);
		}
		
		return;
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		ans=0;
		memset(tag,0,sizeof tag);
		tag[1][1]=1;
		a=b=1;
		solve(1,1,1,tag);
		rep(i,1,n){
			rep(j,1,m)ans+=(tag[i][j]);
		}
		memset(tag2,0,sizeof tag2);
		int ans2=0;
		tag2[1][2]=1;
		a=1;b=2;
		solve(1,2,1,tag2);
		rep(i,1,n){
			rep(j,1,m)ans2+=(tag2[i][j]);
		}
		if(ans>ans2){
			rep(i,1,n){
				rep(j,1,m)printf("%d",tag[i][j]);
				printf("\n");
			}
		}else{
			rep(i,1,n){
				rep(j,1,m){
					printf("%d",tag2[i][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
// 1 4 4