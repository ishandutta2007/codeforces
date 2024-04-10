#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#define uint unsigned int 
#define maxn 2050
using namespace std;

int n,m,i,j,k,a[maxn],b[maxn];
int have[maxn][maxn];

uint sd;
int rd(){
	sd^=sd<<13,sd^=sd>>3,sd^=(sd<<3)+(sd>>29);
	return sd>>1;
}

int ans[maxn],nexans,cnt;
int get(int x,int y){
	if (x>y) swap(x,y);
	if (have[x][y]) return have[x][y];
	printf("? %d %d\n",x,y);
	fflush(stdout);
	cnt++;
	scanf("%d",&have[x][y]); return have[x][y];
	return have[x][y]=ans[x]|ans[y];
}

void doit(int x){
	a[x]=0;
	for(i=1;i<=n;i++) if (i!=x)
		a[i]=get(x,i);
}

int v[maxn]; int cmp(int i,int j){return v[i]<v[j];}
void randshuffle(){
	for(int i=1;i<=n;i++) v[i]=rd(),b[i]=i;
	sort(b+1,b+1+n,cmp);
}

int main(){
	scanf("%d",&n);
	srand(time(0)),sd=(rand()*rand()+rand()+rand())^19260817;
	
//	for(i=1;i<=n;i++) ans[i]=i-1;
	randshuffle();
	int x=1,y=2,z,v1=get(b[x],b[y]),v2;
	for(z=3;z<=n;z++){
		v2=get(b[y],b[z]);
		if (v1==v2) {
			v2=get(b[x],b[z]);
			swap(x,y);
		}
		if (v1!=v2){
			k=v1&v2;
			if (v1>k) x=z,v1=v2; 
		}
	}
	for(i=1;i<=n;i++) if (i!=x&&i!=y){
		if (get(b[i],b[x])>get(b[i],b[y]))
			{doit(b[y]);break;}
		else 
		if (get(b[i],b[x])<get(b[i],b[y]))
			{doit(b[x]);break;}
	}
//	printf("%d\n",cnt);
	printf("! ");
	for(i=1;i<=n;i++) printf("%d ",a[i]);
	fflush(stdout);
}