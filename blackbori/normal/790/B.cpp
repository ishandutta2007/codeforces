#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;

LL B[202020],Dep[202020],C[202020];
LL D[202020][7],n,k,ans;
LL K[202020][7];
vector <LL> V[202020];

int F(LL p,LL d)
{
	int i,j,l;
	LL ret=0;

	B[p] = 1; Dep[p] = d;

	for(i=0;i<V[p].size();i++){
		if(B[V[p][i]] == 0) F(V[p][i],d+1);
		if(Dep[V[p][i]] == d+1){
			for(j=0;j<k;j++){
				D[p][j] += D[V[p][i]][j];
				K[p][j] += K[V[p][i]][(j+k-1)%k];
			}
			C[p] += C[V[p][i]]+1;
		}
	}
	K[p][0]++;

	for(i=0;i<V[p].size();i++){
		if(Dep[V[p][i]] == d+1){
			for(j=0;j<k;j++){
				l = (k+k-j-2)%k;
				ret += K[V[p][i]][j] * (D[p][l]-D[V[p][i]][l]+C[p]-C[V[p][i]]-1);
				if(k-j-2<0) ret += K[V[p][i]][j] * (C[p]-C[V[p][i]]-1);
		//		printf("%lld\n",ret);
			}
			ret += D[V[p][i]][k-1] * (C[p]-C[V[p][i]]-1);
		//	printf("%lld\n",ret);
		}
	}

	for(j=k;j>0;j--) D[p][j] = D[p][j-1];
	D[p][0] = D[p][k]+C[p];
/*	
	printf("%lld\n",p,C[p]);
	for(j=0;j<k;j++) printf("%lld ",D[p][j]);
		printf("\n");
	for(j=0;j<k;j++) printf("%lld ",K[p][j]);
		printf("%lld\n\n",ret);*/

	ans += ret + D[p][0]*2;
	
	return 0;
}

int main()
{
	int i,a,b;

	scanf("%lld%lld",&n,&k);

	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		V[a].push_back(b);
		V[b].push_back(a);
	}

	F(1,2);

	printf("%lld\n",ans/2);

	return 0;
}