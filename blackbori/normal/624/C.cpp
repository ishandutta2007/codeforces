#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int G[505][505],K[505];
char C[505];
vector <int> D,D_0,D_1,D_2;
int n,m,i,j,a,b;

int main()
{	
	scanf("%d%d",&n,&m);
	
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b),a--,b--;
		G[a][b]=G[b][a]=1; K[a]++,K[b]++;
	}
	
	for(i=0;i<n;i++){
		if(K[i] == n-1) D_0.push_back(i);
		else D.push_back(i);
	}
	
	for(i=0;i<D_0.size();i++){
		C[D_0[i]]='b';
		for(j=0;j<n;j++) G[D_0[i]][j]=G[j][D_0[i]]=0;
	}
	
	for(i=0;i<n;i++){
		K[i]=0;
		for(j=0;j<n;j++)K[i]+=G[i][j];
	}
	
	for(i=0;i<D.size();i++){
		if(i==0||G[D[0]][D[i]]) D_1.push_back(D[i]), C[D[i]] = 'a';
		else D_2.push_back(D[i]), C[D[i]] = 'c';
	}
	
	for(i=0;i<D_1.size();i++){
		for(j=0;j<D_2.size();j++){
			if(G[D_1[i]][D_2[j]]){
				printf("No\n");
				return 0;
			}
		}
	}
	
	for(i=0;i<D_1.size();i++){
		if(K[D_1[i]]!=D_1.size()-1){
			printf("No\n");
			return 0;
		}
	}
	
	for(i=0;i<D_2.size();i++){
		if(K[D_2[i]]!=D_2.size()-1){
			printf("No\n");
			return 0;
		}
	}
	
	printf("Yes\n%s\n",C);
	
	return 0;
}