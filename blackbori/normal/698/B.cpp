#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int n,i,root,D[202020],ans,Visited[202020];

int F(int i,int k)
{	
	if(i==root) return 0;
	
	Visited[i] = k;
	
	if(Visited[D[i]] == k){
		ans++;
		D[i] = root;
		return 0;
	}
	else if(Visited[D[i]] != 0) return 0;
	
	F(D[i],k);
	
	return 0;
}

int main()
{
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%d",D+i);
		if(D[i] == i) root=i;
	}
	
	int k=0;
	
	for(i=1;i<=n;i++){
		if(i==root) continue;
	
		if(!Visited[i]) F(i,++k);
	}
	
	printf("%d\n",ans);
	
	for(i=1;i<=n;i++){
		if(D[i] == 0){
			if(root == 0) root=i;
			printf("%d ",root);
		}
		else printf("%d ",D[i]);
	}
	
	return 0;
}