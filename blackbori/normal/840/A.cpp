#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair <int,int> pii;

pii A[201010], B[201010];
int Ans[201010];

int main()
{
	int n,i,a;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&a);
		A[i] = {a,i};
	}

	for(i=0;i<n;i++){
		scanf("%d",&a);
		B[i] = {a,i};
	}

	sort(A,A+n);
	sort(B,B+n);

	for(i=0;i<n;i++){
		Ans[B[i].second] = A[n-i-1].first;
	}

	for(i=0;i<n;i++){
		printf("%d ",Ans[i]);
	}

	printf("\n");

	return 0;
}