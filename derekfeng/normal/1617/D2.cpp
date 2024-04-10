#include<bits/stdc++.h>
using namespace std;
#define ffs fflush(stdout)
int t,n,a[4000],p[10004];
int pos0,pos1,f0,f1;
int c[4][3],d[4];
vector<int>ans;
void sol(){
	scanf("%d",&n),ffs;
	for(int i=1;i<=n/3;i++){
		printf("? %d %d %d\n",i*3-2,i*3-1,i*3),ffs;
		scanf("%d",&a[i]),ffs;
		if(a[i]==0)pos0=i;
		if(a[i]==1)pos1=i;
	}
	d[0]=0,c[0][0]=pos0*3-2,c[0][1]=pos0*3-1,c[0][2]=pos0*3;
	c[1][0]=pos0*3-1,c[1][1]=pos0*3,c[1][2]=pos1*3-2;
	printf("? %d %d %d\n",c[1][0],c[1][1],c[1][2]),ffs;
	scanf("%d",&d[1]),ffs;
	c[2][0]=pos0*3,c[2][1]=pos1*3-2,c[2][2]=pos1*3-1;
	printf("? %d %d %d\n",c[2][0],c[2][1],c[2][2]),ffs;
	scanf("%d",&d[2]),ffs;
	d[3]=1,c[3][0]=pos1*3-2,c[3][1]=pos1*3-1,c[3][2]=pos1*3;
	for(int i=1;i<4;i++)if(d[i]==1){
		f0=c[i-1][0],f1=c[i][2];
		break;
	}
	for(int i=1;i<=n/3;i++)if(i!=pos0&&i!=pos1){
		int i0=i*3-2,i1=i*3-1,i2=i*3;
		int s;
		if(a[i]==0){
			printf("? %d %d %d\n",i0,i1,f1),ffs;
			scanf("%d",&s),ffs;
			if(s==0){
				p[i0]=p[i1]=0;
				printf("? %d %d %d\n",i0,f1,i2),ffs;
				scanf("%d",&s),ffs;
				p[i2]=s;
			}else{
				p[i2]=0;
				printf("? %d %d %d\n",i0,f1,i2),ffs;
				scanf("%d",&s),ffs;
				p[i0]=s,p[i1]=s^1;
			}
		}else{
			printf("? %d %d %d\n",i0,i1,f0),ffs;
			scanf("%d",&s),ffs;
			if(s==0){
				p[i2]=1;
				printf("? %d %d %d\n",i0,f0,i2),ffs;
				scanf("%d",&s),ffs;
				p[i0]=s,p[i1]=s^1;
			}else{
				p[i0]=p[i1]=1;
				printf("? %d %d %d\n",i0,f0,i2),ffs;
				scanf("%d",&s),ffs;
				p[i2]=s;
			}
		}
	}
	for(int i=0;i<3;i++){
		if(c[0][i]!=f0&&c[0][i]!=f1){
			printf("? %d %d %d\n",f0,f1,c[0][i]),ffs;
			scanf("%d",&p[c[0][i]]),ffs;
		}
		if(c[3][i]!=f0&&c[3][i]!=f1){
			printf("? %d %d %d\n",f0,f1,c[3][i]),ffs;
			scanf("%d",&p[c[3][i]]),ffs;
		}
	}
	p[f0]=0,p[f1]=1;
	ans.clear();
	for(int i=1;i<=n;i++)if(p[i]==0)ans.push_back(i);
	printf("! %d ",ans.size());for(auto x:ans)printf("%d ",x);
	puts(""),ffs;
}
int main(){
	scanf("%d",&t),ffs;
	while(t--)sol();
}