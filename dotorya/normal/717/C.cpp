#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 100000 + 5;

ll A[MN];

int main(){
	II(N);
	for(int i=0;i<N;i++) scanf("%lld",&A[i]);
	ll ans = 0;
	sort(A, A+N);
	for(int i=0;i<N;i++){
		ans = (ans + A[i] * A[N-1-i]) % 10007;
	}
	printf("%lld\n",ans);
	return 0;
}