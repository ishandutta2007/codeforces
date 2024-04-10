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
const int MAXN=110,nextx[4]={1,0,-1,0},nexty[4]={0,1,0,-1};
int T,n,m,k;
char state[MAXN][MAXN];
int valid(int x,int y){
	return x>=1 && x<=n && y>=1 && y<=m;
}
void place(int x1,int y1,int x2,int y2){
	rep(i,0,25){
		int flag=1;
		rep(k,0,3){
			int x=x1+nextx[k],y=y1+nexty[k];
			if(valid(x,y) && state[x][y]=='a'+i)flag=0;
			x=x2+nextx[k],y=y2+nexty[k];
			if(valid(x,y) && state[x][y]=='a'+i)flag=0;
		}
		if(flag){
			state[x1][y1]=state[x2][y2]='a'+i;
			break;
		}
	}
}
void construct(int x1,int y1,int x2,int y2,int k){
	for(ll x=x1;x<x2;x+=2){
		for(ll y=y1;y<y2;y+=2){
			if(k){
				place(x,y,x,y+1);
				place(x+1,y,x+1,y+1);
				k-=2;
			}else{
				place(x,y,x+1,y);
				place(x,y+1,x+1,y+1);
			}
		}
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		memset(state,0,sizeof state);
		if(even(n) && even(m)){
			if(k%2)printf("NO\n");
			else{
				printf("YES\n"); 
				construct(1,1,n,m,k);
				rep(i,1,n){
					rep(j,1,m)printf("%c",state[i][j]);
					printf("\n");
				}
			}
		}else if(even(n) && odd(m)){
			if(k*2<=n*m-n && (k%2)==0){
				printf("YES\n");
				for(ll x=1;x<n;x+=2){
					place(x,m,x+1,m);
					construct(1,1,n,m-1,k);
				}
				rep(i,1,n){
					rep(j,1,m)printf("%c",state[i][j]);
					printf("\n");
				}
			}
			else printf("NO\n");
		}else{
			if(k>=m/2 && (k-m/2)%2==0){
				printf("YES\n");
				for(ll y=1;y<m;y+=2){
					place(1,y,1,y+1);
				}
				construct(2,1,n,m,k-m/2);
				rep(i,1,n){
					rep(j,1,m)printf("%c",state[i][j]);
					printf("\n");
				}
			}
			else printf("NO\n");
		}
	}

	return 0;
}