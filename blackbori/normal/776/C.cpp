#include <cstdio>
#include <map>

using namespace std;

typedef long long LL;

map <LL,int> M;

LL n,k,s,i,j,a,ans;

int main()
{
	scanf("%lld%lld",&n,&k);

	if(k==1){
		M[s]++;
		for(i=0;i<n;i++){
			scanf("%lld",&a);
			s += a;
			ans += M[s-1];
			M[s]++;
		}
		printf("%lld\n",ans);

		return 0;
	}

	if(k==-1){
		M[s]++;
		for(i=0;i<n;i++){
			scanf("%lld",&a);
			s += a;
			ans += M[s-1] + M[s+1];
			M[s]++;
		}
		printf("%lld\n",ans);
		
		return 0;
	}

	M[s]++;
	for(i=0;i<n;i++){
		scanf("%lld",&a);
		s += a;
		for(j=1;(-1e15<j && j<1e15);j*=k){
			ans += M[s-j];
		}
		M[s]++;
	}

	printf("%lld\n",ans);

	return 0;
}