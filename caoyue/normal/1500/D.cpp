#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1515;
const int INF=1e9+7;
int n,q,V;
int c[N][N],w1[N][N][12],p1[N][N][12],w2[N][N][12],p2[N][N][12];
int h[N*N],s[N*N],g[N],id[15],dd[N*N],nd[15],sm[N],fr1[N][N],fr2[N][N],ls[N*N];
int check1(int x,int L,int R,int C){
	int v1=0,v2=0;
	rep(j,q+1){
		if(w1[x][L][j]==C){
			v1+=(p1[x][L][j]%V);
			if(fr1[x][p1[x][L][j]/V]<=R)return v1;
			break;
		}
	}
	rep(j,q+1){
		if(w1[x][R][j]==C){
			v2+=(p1[x][R][j]%V);
			break;
		}
	}
	return v1-v2+(c[x][R]==C);
}
int check2(int x,int L,int R,int C){
	int v1=0,v2=0;
	rep(j,q+1){
		if(w2[L][x][j]==C){
			v1+=(p2[L][x][j]%V);
			if(fr2[p2[L][x][j]/V][x]<=R)return v1;
			break;
		}
	}
	rep(j,q+1){
		if(w2[R][x][j]==C){
			v2+=(p2[R][x][j]%V);
			break;
		}
	}
	return v1-v2+(c[R][x]==C);
}
void expand(int i,int j,int &x,int &y){
	while(1){
		if(i-x<1||j-x<1)return;
		if(p1[i-x][j-x][q+1]/V<=j)return;
		if(p2[i-x][j-x][q+1]/V<=i)return;
		rep(k,q){
			if(p1[i-x][j-x][k]/V>j)break;
			if(!h[w1[i-x][j-x][k]]){
				if(y==q){
					for(int o=k-1;o;o--){
						h[w1[i-x][j-x][o]]-=check1(i-x,j-x,j,w1[i-x][j-x][o]);
						if(!h[w1[i-x][j-x][o]]){
							id[y]=dd[w1[i-x][j-x][o]]=0;
							y--;
						}
					}
					return;
				}
				id[++y]=w1[i-x][j-x][k];
				dd[w1[i-x][j-x][k]]=y;
			}
			h[w1[i-x][j-x][k]]+=check1(i-x,j-x,j,w1[i-x][j-x][k]);
		}
		rep(k,q){
			if(p2[i-x+1][j-x][k]/V>i)break;
			if(!h[w2[i-x+1][j-x][k]]){
				if(y==q){
					for(int o=q;o;o--){
						if(p1[i-x][j-x][o]/V>j)continue;
						h[w1[i-x][j-x][o]]-=check1(i-x,j-x,j,w1[i-x][j-x][o]);
						if(!h[w1[i-x][j-x][o]]){
							id[y]=dd[w1[i-x][j-x][o]]=0;
							y--;
						}
					}
					for(int o=k-1;o;o--){
						h[w2[i-x+1][j-x][o]]-=check2(j-x,i-x+1,i,w2[i-x+1][j-x][o]);
						if(!h[w2[i-x+1][j-x][o]]){
							id[y]=dd[w2[i-x+1][j-x][o]]=0;
							y--;
						}
					}
					return;
				}
				id[++y]=w2[i-x+1][j-x][k];
				dd[w2[i-x+1][j-x][k]]=y;
			}
			h[w2[i-x+1][j-x][k]]+=check2(j-x,i-x+1,i,w2[i-x+1][j-x][k]);
		}
		x++;
	}
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,n)rep(j,n)scanf("%d",&c[i][j]);
	V=n+q+3;
	rep(i,n){
		rep(j,q+1){
			w1[i][n+1][j]=n*n+j;
			p1[i][n+1][j]=n+1;
		}
		rep(j,n)s[c[i][j]]=0;
		for(int j=n;j;j--){
			w1[i][j][1]=c[i][j];
			p1[i][j][1]=j;
			int id=(i*n+j),cc=1;
			h[c[i][j]]=id;
			rep(k,q+1){
				if(h[w1[i][j+1][k]]!=id){
					h[w1[i][j+1][k]]=id;
					w1[i][j][++cc]=w1[i][j+1][k];
					p1[i][j][cc]=p1[i][j+1][k];
					if(cc==q+1)break;
				}
			}
		}
		rep(j,n)ls[c[i][j]]=n+1;
		for(int j=n+1;j;j--){
			if(j<=n){
				s[c[i][j]]++;
				fr1[i][j]=ls[c[i][j]];
				bool fl=1;
				rep(k,q+1)if(w1[i][j][k]==w1[i][j+1][q+1]){
					fl=0;
					break;
				}
				if(fl){
					ls[w1[i][j+1][q+1]]=j;
					s[w1[i][j+1][q+1]]=0;
				}
			}
			rep(k,q+1)p1[i][j][k]=V*p1[i][j][k]+s[w1[i][j][k]];
		}
	}
	rep(i,n){
		rep(j,q+1){
			w2[n+1][i][j]=n*n+j;
			p2[n+1][i][j]=n+1;
		}
		rep(j,n)s[c[j][i]]=0;
		for(int j=n;j;j--){
			w2[j][i][1]=c[j][i];
			p2[j][i][1]=j;
			int id=(i*n+j+n*n),cc=1;
			h[c[j][i]]=id;
			rep(k,q+1){
				if(h[w2[j+1][i][k]]!=id){
					h[w2[j+1][i][k]]=id;
					w2[j][i][++cc]=w2[j+1][i][k];
					p2[j][i][cc]=p2[j+1][i][k];
					if(cc==q+1)break;
				}
			}
		}
		rep(j,n)ls[c[j][i]]=n+1;
		for(int j=n+1;j;j--){
			if(j<=n){
				s[c[j][i]]++;
				fr2[j][i]=ls[c[j][i]];
				bool fl=1;
				rep(k,q+1)if(c[j][i]==w2[j+1][i][q+1]){
					fl=0;
					break;
				}
				if(fl){
					ls[w2[j+1][i][q+1]]=j;
					s[w2[j+1][i][q+1]]=0;
				}
			}
			rep(k,q+1)p2[j][i][k]=V*p2[j][i][k]+s[w2[j][i][k]];
		}
	}
	memset(h,0,sizeof(h));
	rep(i,n){
		id[1]=c[i][n];
		dd[c[i][n]]=1;
		h[c[i][n]]=1;
		g[n]=1;
		int nw=1;
		expand(i,n,g[n],nw);
		for(int j=n-1;j;j--){
			if(g[j+1]==1){
				h[c[i][j+1]]=dd[c[i][j+1]]=0;
				h[c[i][j]]=dd[c[i][j]]=1;
				id[1]=c[i][j];
				g[j]=1;
			}
			else{
				g[j]=g[j+1]-1;
				int x=i-g[j+1]+1,y=j+2-g[j+1];
				rep(k,q){
					if(p1[x][y][k]/V>j+1)break;
					h[w1[x][y][k]]-=check1(x,y,j+1,w1[x][y][k]);
				}
				y=j+1;
				x++;
				rep(k,q){
					if(p2[x][y][k]/V>i)break;
					h[w2[x][y][k]]-=check2(j+1,x,i,w2[x][y][k]);
				}
				int nn=0;
				rep(k,nw)if(h[id[k]])nd[++nn]=id[k];
				rep(k,nw)dd[id[k]]=0;
				memset(id,0,sizeof(id));
				nw=nn;
				rep(k,nw){
					id[k]=nd[k];
					dd[id[k]]=k;
				}
			}
			expand(i,j,g[j],nw);
		}
		rep(j,n){
			sm[1]++;
			sm[g[j]+1]--;
		}
		h[c[i][1]]=0;
	}
	rep(i,n)sm[i]+=sm[i-1];
	rep(i,n)printf("%d\n",sm[i]);
	return 0;
}