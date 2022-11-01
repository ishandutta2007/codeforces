#include<iostream>
using namespace std;
#define R register int
#define I inline
I void Add(int&x,const int y){
	x+=y;
	if(x>=3){
		x-=3;
	}
}
I void Swap(int&x,int&y){
	int t=x;
	x=y;
	y=t;
}
int G[64][64],col[256],t[6000][257],pre[256];
I bool Calc(const int n,const int m){
	int cur=0;
	for(R i=0;i!=m;i++){
		int p;
		if(t[cur][i]==0){
			p=-1;
			for(R j=cur+1;j!=n;j++){
				if(t[j][i]!=0){
					p=j;
					break;
				}
			}
		}else{
			p=cur;
		}
		if(p!=-1){
			pre[cur]=i;
			if(p!=cur){
				for(R j=i;j<=m;j++){
					Swap(t[cur][j],t[p][j]);
				}
			}
			int inv=t[cur][i];
			for(R j=cur+1;j!=n;j++){
				if(t[j][i]!=0){
					int tem=inv==t[j][i]?1:2;
					for(R k=i;k<=m;k++){
						if(t[cur][k]!=0){
							Add(t[j][k],tem==t[cur][k]?2:1);
						}
					}
				}
			}
			cur++;
		}
	}
	for(R i=cur;i!=n;i++){
		if(t[i][m]!=0){
			return false;
		}
	}
	cur--;
	for(R i=m-1;i!=-1;i--){
		if(cur!=-1&&pre[cur]==i){
			int sum=t[cur][m];
			for(R j=i+1;j!=m;j++){
				sum=(sum+6-t[cur][j]*col[j])%3;
			}
			col[i]=t[cur][i]*sum%3;
			cur--;
		}else if(col[i]==-1){
			col[i]=0;
		}
	}
	return true;
}
I void Solve(){
	int n,m,x,y,ct=0;
	cin>>n>>m;
	for(R i=0;i!=n;i++){
		for(R j=0;j!=n;j++){
			G[i][j]=-1;
		}
	}
	for(R i=0;i!=m;i++){
		scanf("%d%d%d",&x,&y,col+i);
		G[x-1][y-1]=G[y-1][x-1]=i;
	}
	for(R i=2;i!=n;i++){
		for(R j=1;j!=i;j++){
			if(G[i][j]!=-1){
				for(R k=0;k!=j;k++){
					if(G[i][k]!=-1&&G[j][k]!=-1){
						for(R l=0;l<=m;l++){
							t[ct][l]=0;
						}
						if(col[G[i][j]]!=-1){
							Add(t[ct][m],3-col[G[i][j]]);
						}else{
							t[ct][G[i][j]]=1;
						}
						if(col[G[i][k]]!=-1){
							Add(t[ct][m],3-col[G[i][k]]);
						}else{
							t[ct][G[i][k]]=1;
						}
						if(col[G[j][k]]!=-1){
							Add(t[ct][m],3-col[G[j][k]]);
						}else{
							t[ct][G[j][k]]=1;
						}
						ct++;
					}
				}
			}
		}
	}
	while(ct<m){
		for(R i=0;i<=m;i++){
			t[ct][i]=0;
		}
		ct++;
	}
	if(Calc(ct,m)==true){
		for(R i=0;i!=m;i++){
			cout<<(col[i]==0?3:col[i])<<' ';
		}
	}else{
		cout<<-1;
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}