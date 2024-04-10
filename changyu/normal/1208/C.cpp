#include<cstdio>
const int N=1000,KEY[4][4]={
	{0,1,4,5},
	{2,3,6,7},
	{8,9,12,13},
	{10,11,14,15}
};
int ans[N][N],n,t;
void Paint(int x,int y){
	for(int i=0;i<4;i++)
	  for(int j=0;j<4;j++)
		ans[x+i][y+j]=KEY[i][j]+t;
}
signed main(){
	scanf("%d",&n);
	for(int i=0;i<n;i+=4)
	  for(int j=0;j<n;j+=4)
		Paint(i,j),t+=16;
	for(int i=0;i<n;i++){
	  for(int j=0;j<n;j++)printf("%d ",ans[i][j]);
	  puts("");
	}return 0;
}