#include<bits/stdc++.h>
using namespace std;

int n,m,q;
int a[1005][1005];
int p[1111111];
inline int z(int x,int y){return x*m+y;}
int f(int x){return x==p[x]?x:p[x]=f(p[x]);}
void merge(int x,int y){ //x -> y
	p[f(x)]=f(y);
}
int main() {
	iota(p,p+1111111,0);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==2){
				merge(z(i,j),z(i+1,j));
			}
		}
	}
	while(q--){
		int y;
		scanf("%d",&y);
		--y;
		int x=z(0,y)/m;
		while(x<n){
			merge(z(x,y),z(x+1,y));
			if(a[x][y]==1){
				a[x][y]=2;
				y++;
			}
			else if(a[x][y]==3){
				a[x][y]=2;
				y--;
			}
			int t=f(z(x,y));
			x=t/m;
		}
		printf("%d ",y+1);
	}
	return 0;
}