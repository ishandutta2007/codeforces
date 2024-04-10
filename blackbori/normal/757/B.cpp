#include <cstdio>

using namespace std;

int ans,n;
int D[101010];

int main()
{
	int i,j,k,a;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&a);
		D[a]++;
	}

	for(i=2;i<=100000;i++){
		for(j=i,k=0;j<=100000;j+=i){
			k += D[j];
		}
		if(k>ans) ans=k;
	}

	if(ans == 0 && D[1] != 0) ans = 1;

	printf("%d\n",ans);

	return 0;
}