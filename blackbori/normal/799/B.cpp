#include <cstdio>
#include <map>

using namespace std;

map <int,int> M[4];
map <int,int>::iterator it;
int n,m,a,b,c,i;

int A[202020], B[202020], C[202020];

int main()
{
	scanf("%d",&n);

	for(i=0;i<n;i++) scanf("%d",A+i);
	for(i=0;i<n;i++) scanf("%d",B+i);
	for(i=0;i<n;i++) scanf("%d",C+i);

	for(i=0;i<n;i++){
		a = A[i], b = B[i], c = C[i];
		M[b][a]++;
		M[c][a]++;
	}

	scanf("%d",&m);

	for(i=0;i<m;i++){
		scanf("%d",&a);
		if(M[a].empty()) printf("-1\n");
		else{
			it = M[a].begin();
			b = it->first;
			printf("%d\n",b);

			M[1].erase(b);
			M[2].erase(b);
			M[3].erase(b);
		}
	}

	return 0;
}