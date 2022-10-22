/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
double sq(double x){return x*x;}
int n[3],tot,r[3],a[2];
double add[2][10],ac[2];
const int hav[][3]={{0,0,2},{0,1,1},{0,2,0},{1,0,1},{1,1,0},{2,0,0}};
double ans;
int cnt[11][3];
void dfs(int x=1,double now=0){
	if(x==tot+3>>1){ans=max(ans,now);return;}
	if(x==tot+1>>1&&tot&1){
		for(int i=0;i<3;i++)if(n[i]){
			cnt[x][i]=1;
			double add0=(cnt[x][0]*ac[0]+cnt[x][1]*ac[1])+cnt[x][2]*(cnt[x][0]*add[0][0]+cnt[x][1]*add[1][0]);
			for(int j=1;j<x;j++)
				add0+=cnt[x][2]*(add[0][x-j]*cnt[j][0]+add[1][x-j]*cnt[j][1])+cnt[j][2]*(add[0][x-j]*cnt[x][0]+add[1][x-j]*cnt[x][1]);
			dfs(x+1,now+add0);
			cnt[x][i]=0;
		}
	}
	else
		for(int i=0;i<6;i++){
			for(int j=0;j<3;j++)n[j]-=hav[i][j],cnt[x][j]+=hav[i][j];
//			cout<<n[0]<<" "<<n[1]<<" "<<n[2]<<"\n";
			if(n[0]>=0&&n[1]>=0&&n[2]>=0){
				double add0=(cnt[x][0]*ac[0]+cnt[x][1]*ac[1])+cnt[x][2]*(cnt[x][0]*add[0][0]+cnt[x][1]*add[1][0]);
				for(int j=1;j<x;j++)
					add0+=cnt[x][2]*(add[0][x-j]*cnt[j][0]+add[1][x-j]*cnt[j][1])+cnt[j][2]*(add[0][x-j]*cnt[x][0]+add[1][x-j]*cnt[x][1]);
				dfs(x+1,now+add0);
			}
			for(int j=0;j<3;j++)n[j]+=hav[i][j],cnt[x][j]-=hav[i][j];
		}
}
int main(){
	cin>>n[0]>>n[1]>>n[2]>>r[0]>>r[1]>>r[2]>>a[0]>>a[1];
	tot=n[0]+n[1]+n[2];
	for(int i=0;i<2;i++)for(int j=0;j<10;j++){
		double l1=-sqrt(sq(r[i])-1),r1=sqrt(sq(r[i])-1),l2=j-sqrt(sq(r[2])-1),r2=j+sqrt(sq(r[2])-1);
		add[i][j]=a[i]*max(0.,min(r1,r2)-max(l1,l2));
		ac[i]=a[i]*(r1-l1);
//		printf("add[%d][%d]=%.5lf\n",i,j,add[i][j]);
	}
	dfs();
	printf("%.100lf\n",ans);
	return 0;
}
/*1
1 0 0
10 10 10
100 100
*/
/*2
1 0 1
10 10 10
100 100
*/
/*3
1 1 1
2 2 2
10 10
*/
/*4
5 5 4
6 5 3
121 129
*/