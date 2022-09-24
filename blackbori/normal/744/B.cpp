#include <cstdio>

#define min(a,b) (a)<(b)?(a):(b)

using namespace std;

int D[1010][20],P[1010],Ans[1010],n;

int main()
{
	int i,j,k,c;

	scanf("%d",&n);

	for(k=1;k<=n;k++) Ans[k] = 1e9+1;

	for(i=k=0;i<1<<20;i++){
		for(c=j=0;j<20;j++) if(i&(1<<j)) c++;
		if(c==10){
			k++;
			for(j=0;j<20;j++){
				if(i&(1<<j)) D[k][j] = 1;
				else D[k][j] = 0;
			}
		}
		if(k==n) break;
	}

	for(i=0;i<20;i++){
		for(j=0;j<i;j++){
			for(k=1;k<=n;k++) if(D[k][i] != D[k][j]) break;
			if(k==n+1){
				P[i] = -1;
				break;
			}
		}
		if(P[i] != -1){
			for(k=1;k<=n;k++) P[i] += D[k][i];
		}
	}

	for(i=0;i<20;i++){
		if(P[i] != -1 && P[i] != 0){
			printf("%d\n",P[i]);
			for(k=1;k<=n;k++) if(D[k][i]) printf("%d ",k);
			printf("\n");
			fflush(stdout);

			for(k=1;k<=n;k++){
				scanf("%d",&c);
				if(D[k][i] != 1) Ans[k] = min(Ans[k],c);
			}
		}
	}

	printf("-1\n");
	for(k=1;k<=n;k++) printf("%d ",Ans[k]);
	printf("\n");
	fflush(stdout);

	return 0;
}