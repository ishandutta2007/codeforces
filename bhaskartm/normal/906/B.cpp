#include<cstdio>
const int vx[4]={-1,0,0,1},vy[4]={0,-1,1,0};
int n,m,p[100010];
int nei(int i,int j){
	int x1=i/m,y1=i%m,
		x2=j/m,y2=j%m;
	for(int d=0;d<4;d++)if(x2==x1+vx[d]&&y2==y1+vy[d])return 1;
	return 0;
}
void swp(int&a,int&b){int t=a;a=b;b=t;}
bool dfs(int i){
	if(i==n*m)return 1;
	int x=i/m,y=i%m;
	for(int j=i;j<n*m;j++){
		swp(p[i],p[j]);
		bool ok=1;
		if(x&&nei(p[i],p[(x-1)*m+y]))ok=0;
		if(y&&nei(p[i],p[x*m+y-1]))ok=0;
		if(ok){
			if(dfs(i+1))return 1;
		}
		swp(p[i],p[j]);
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)p[i]=i;
	if(dfs(0)){
		puts("YES");
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)printf("%d%c",p[i*m+j]+1," \n"[j==m-1]);
	}
	else puts("NO");
}