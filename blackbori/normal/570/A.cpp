#include <bits/stdc++.h>

using namespace std;

int D[103];

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	
	int i,j,a;
	
	D[0] = -1;
	for(i=0; i<n; i++){
		int mx=-1,ix=0;
		for(j=0; j<m; j++){
			scanf("%d",&a);
			if(a>mx){
				mx=a,ix=j+1;
			}
		}
		D[ix]++;
	}
	
	int ans=0;
	for(i=0; i<m; i++){
		if(D[i+1] > D[ans]) ans=i+1;
	}
	
	printf("%d\n",ans);
	
	return 0;
}