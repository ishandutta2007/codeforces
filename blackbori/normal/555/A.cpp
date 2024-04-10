#include <bits/stdc++.h>

std::vector <int> V;
int N,M;

int main()
{
	scanf("%d%d",&N,&M);
	int i,j,a,cnt=0,b;
	for(i=0; i<M; i++){
		scanf("%d",&a);
		V.clear();
		for(j=0; j<a; j++) scanf("%d",&b),V.push_back(b);
		j=0;
		if(V[0]==1){
			for(; j<a; j++){
				if(V[j]-1 != j) break;
			}
			cnt += (a-j+1);
		}
		else cnt+=a;
	}
	printf("%d\n",cnt-1+cnt-M);
	
	return 0;
}