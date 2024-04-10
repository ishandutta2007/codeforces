#include<stdio.h>
const int MAXN = 100005;
int u[MAXN],v[MAXN],color[MAXN],d[MAXN];
int main(){
	int n;
	int e=0;
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&color[i]);
	}
	for (int i=1;i<n;i++){
		if (color[u[i]]!=color[v[i]]) e++,d[u[i]]++,d[v[i]]++;
	}
	for (int i=1;i<=n;i++){
		if (e==d[i]){
			printf("YES\n%d",i);
			return 0;
		}
	}
	printf("NO");
	return 0;
}