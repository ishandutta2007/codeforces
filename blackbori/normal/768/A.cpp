#include <cstdio>
#include <algorithm>

using namespace std;

int n,i,ans;
int A[101010];

int main()
{
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",A+i);
	}

	sort(A,A+n);

	for(i=1;i<n-1;i++){
		if(A[0] != A[i] && A[i] != A[n-1]) ans++;
	}

	printf("%d\n",ans);

	return 0;
}