#include<iostream>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define N 300001
inline int Max(const int x,const int y){
	return x>y?x:y;
}
vector<int>G[N];
int h[N],dep[N],f[N][18],g1[N][18],g2[N][18];
I void PreDFS(int x,int F){
	f[x][0]=F;
	for(R i=1;i!=18&&f[x][i-1]!=0;i++){
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int T:G[x]){
		if(T!=F){
			PreDFS(T,x);
			if(dep[T]>dep[h[x]]){
				h[x]=T;
			}
		}
	}
	if(h[x]!=0){
		dep[x]=dep[h[x]]+1;
	}
}
I void ReDFS(int x){
	dep[x]=-1;
	for(int T:G[x]){
		if(T!=f[x][0]&&T!=h[x]&&dep[T]>dep[x]){
			dep[x]=dep[T];
		}
	}
	g1[x][0]=dep[x]-dep[f[x][0]];
	g2[x][0]=dep[x]+dep[f[x][0]]+2;
	//printf("G%d %d %d\n",x,g1[x][0],g2[x][0]);
	dep[x]=dep[f[x][0]]+1;
	for(R i=1;i!=18&&f[x][i]!=0;i++){
		g1[x][i]=Max(g1[x][i-1],g1[f[x][i-1]][i-1]);
		g2[x][i]=Max(g2[x][i-1],g2[f[x][i-1]][i-1]);
	}
	for(int T:G[x]){
		if(T!=f[x][0]){
			ReDFS(T);
		}
	}
}
I void Solve(){
	int n,x,y;
	cin>>n;
	for(R i=0;i<=n;i++){
		dep[i]=h[i]=0;
		vector<int>().swap(G[i]);
		for(R j=0;j!=18;j++){
			f[i][j]=0;
			g1[i][j]=g2[i][j];
		}
	}
	for(R i=1;i!=n;i++){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dep[0]=-1;
	PreDFS(1,0);
	ReDFS(1);
	/*for(R i=1;i<=n;i++){
		printf("%d ",h[i]);
	}
	puts("");*/
	x=1;
	for(R i=2;i<=n;i++){
		if(dep[i]>dep[x]){
			x=i;
		}
	}
	//printf("X%d %d\n",x,dep[x]);
	for(R i=1;i<=n;i++){
		if(i>dep[x]){
			printf("%d ",dep[x]);
		}else{
			int lf=i,rt=dep[x],mid,ans;
			//printf("I%d %d %d\n",i,lf,rt);
			ans=rt;
			rt--;
			while(lf<=rt){
				mid=lf+rt>>1;
				int len=mid-i,y=x;
				for(R j=17;j!=-1;j--){
					if((len>>j&1)==1){
						y=f[y][j];
					}
				}
				int q=i+dep[y]>>1,tem=y;
				//printf("M%d %d %d %d\n",mid,len,y,q);
				bool tag=true;
				for(R j=17;j!=-1;j--){
					if(dep[f[y][j]]>=q){
						if(g1[y][j]+dep[tem]>mid-i){
							tag=false;
							goto Fail;
						}
						y=f[y][j];
					}
				}
				for(R j=17;j!=-1;j--){
					if(dep[f[y][j]]>-1){
						if(g2[y][j]>mid){
							tag=false;
							goto Fail;
						}
						y=f[y][j];
					}
				}
				if(g2[1][0]>mid){
					tag=false;
				}
				Fail:;
				if(tag==true){
					ans=mid;
					rt=mid-1;
				}else{
					lf=mid+1;
				}
			}
			printf("%d ",ans);
		}
	}
	puts("");
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
/*
1
6
1 2
1 3
2 4
3 5
1 6
*/