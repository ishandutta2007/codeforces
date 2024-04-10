#include <cstdio>

using namespace std;

int D[202020],B[202020];
int n,s,ans;

int main()
{
	int i,j,a;
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		scanf("%d",D+i);
	}

	for(i=1;i<=n;i++){
		if(!B[i]){
			ans++, j=i;
			while(true){
				B[j]=1, j=D[j];
				if(j==i) break;
			}
		}
	}

	for(i=0;i<n;i++){
		scanf("%d",&a);
		s += a;
	}

	printf("%d\n",(ans>1?ans:0)+1-s%2);

	return 0;
}