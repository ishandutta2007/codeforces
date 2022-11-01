#include<stdio.h>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
int a[12][100000],pos[1100000],Last[4096],pre[1100000];
vector<int>A[100000];
vector<bool>B[12];
bitset<4096>Q[100012];
int main(){
	int n,m,q,tot,x,y,opt;
	scanf("%d%d%d",&n,&m,&q);
	for(R i=0;i!=m;i++){
		for(R j=0;j!=n;j++){
			scanf("%d",a[i]+j);
			A[j].push_back(a[i][j]);
		}
	}
	for(R i=0;i!=n;i++){
		sort(A[i].begin(),A[i].end());
		tot=unique(A[i].begin(),A[i].end())-A[i].begin();
		while(A[i].size()>tot){
			A[i].pop_back();
		}
		pos[i]=tot-1;
		for(R j=0;j!=m;j++){
			x=lower_bound(A[i].begin(),A[i].end(),a[j][i])-A[i].begin();
			for(R k=0;k!=x;k++){
				B[j].push_back(true);
			}
			for(R k=x;k!=pos[i];k++){
				B[j].push_back(false);
			}
		}
	}
	for(R i=1;i!=n;i++){
		pos[i]+=pos[i-1];
	}
	for(R i=0;i!=1<<m;i++){
		Last[i]=-1;
	}
	tot=0;
	for(R i=0;i!=pos[n-1];i++){
		x=0;
		for(R j=0;j!=m;j++){
			x=x<<1|B[j][i];
		}
		if(Last[x]==-1){
			Last[x]=tot;
			for(R j=0;j!=m;j++){
				Q[j][tot]=B[j][i];
			}
			tot++;
		}
		pre[i]=Last[x];
	}
	tot=m;
	for(R i=0;i!=q;i++){
		scanf("%d%d%d",&opt,&x,&y);
		x--;
		y--;
		if(opt==1){
			Q[tot]=Q[x]|Q[y];
			tot++;
		}else if(opt==2){
			Q[tot]=Q[x]&Q[y];
			tot++;
		}else{
			int r=pos[y],l=y==0?0:pos[y-1],ct=0;
			for(R j=l;j!=r;j++){
				if(Q[x][pre[j]]==0){
					break;
				}
				ct++;
			}
			printf("%d\n",A[y][ct]);
		}
	}
	return 0;
}