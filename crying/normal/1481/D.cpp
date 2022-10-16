#include<bits/stdc++.h>
#define next Cry_For_theMoon
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(b);i>=(a);i--)
typedef long long ll;
typedef double db;
using namespace std;
const int MAXN=1010;
int T,n,m,edge[MAXN][MAXN];
char tmp; 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n){
			rep(j,1,n){
				scanf(" %c",&tmp);
				if(i==j)continue;
				if(tmp=='a')edge[i][j]=0;
				else edge[i][j]=1;
			}
		}
		rep(i,1,n){
			rep(j,i+1,n){
				if(edge[i][j]==edge[j][i]){
					printf("YES\n"); 
					int now=j;printf("%d ",i);
					while(m--){
						printf("%d ",now);
						if(now==j)now=i;else now=j;
					}
					goto END;
				}
			}
		}
		if(m&1){
			printf("YES\n");
			int now=2;printf("1 ");
			while(m--){
				printf("%d ",now);
				if(now==2)now=1;else now=2;
			}
			goto END;
		}
		if(n>=3){
			int x,y,z;
			if(edge[1][2]==edge[2][3])x=1,y=2,z=3;
			else if(edge[1][3]==edge[3][2])x=1,y=3,z=2;
			else if(edge[2][3]==edge[3][1])x=2,y=3,z=1;
			else if(edge[2][1]==edge[1][3])x=2,y=1,z=3;
			else if(edge[3][1]==edge[1][2])x=3,y=1,z=2;
			else if(edge[3][2]==edge[2][1])x=3,y=2,z=1;
			//x->y = y->z
			printf("YES\n");
			if((m/2)&1){
				int now=x;printf("%d ",x);
				while(m){
					if(now==x)printf("%d %d ",y,z),now=z;
					else printf("%d %d ",y,x),now=x;
					m-=2;
				}
				goto END;
			}else{
				printf("%d ",y);
				while(m){
					printf("%d %d %d %d\n",x,y,z,y);	
					m-=4;
				}
				goto END;
			}
		}
		printf("NO\n");
		continue;
		END:printf("\n");
	}
	
	return 0;
}