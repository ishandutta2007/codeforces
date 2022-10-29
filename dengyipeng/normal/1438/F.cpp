#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 262145
#define uint unsigned int 
using namespace std;

int n,cnt[maxn],i,j,k;
uint sd;

int rd(){
	sd^=sd<<23,sd^=sd>>13,sd^=(sd<<3)*(sd>>17);
	return sd>>1;
}

int main(){
	sd=19260817;
	scanf("%d",&n),n=(1<<n)-1;
	for(i=1;i<=420;i++){
		int x=rd()%n+1,y=rd()%n+1,z=rd()%n+1;
		while (x==y||x==z||y==z) 
			x=rd()%n+1,y=rd()%n+1,z=rd()%n+1;
		printf("? %d %d %d\n",x,y,z);
		fflush(stdout);
		scanf("%d",&x),cnt[x]++;
	}
	int id1=0,id2=0;
	for(i=1;i<=n;i++) {
		if (cnt[i]>cnt[id1]) id2=id1,id1=i; else 
			if (cnt[i]>cnt[id2]) id2=i;
	}
	for(i=1;i<=n;i++) if (i!=id1&&i!=id2){
		printf("? %d %d %d\n",i,id1,id2);
		fflush(stdout);
		scanf("%d",&k); 
		if (k==i) {
			printf("! %d\n",k);
			fflush(stdout);
			return 0;
		}
	}
}