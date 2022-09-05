#include<cstdio>
#include<algorithm>
using namespace std;
int x[50],y[50];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=4*n+1;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1;i<=4*n+1;i++){
		int Mx=0,mx=50,My=0,my=50;
		for(int j=1;j<=4*n+1;j++)if(j!=i){
			Mx=max(Mx,x[j]);
			mx=min(mx,x[j]);
			My=max(My,y[j]);
			my=min(my,y[j]);
		}
		bool ok=1;
		for(int j=1;j<=4*n+1;j++)if(j!=i){
			if(x[j]!=mx&&x[j]!=Mx&&y[j]!=My&&y[j]!=my)ok=0;
		}
		if(ok&&Mx-mx==My-my){
			printf("%d %d\n",x[i],y[i]);
			return 0;
		}
	}
	return 0;
}