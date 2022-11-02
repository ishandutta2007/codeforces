#include <bits/stdc++.h>
#define maxn 1009
using namespace std;
int ans[1009][maxn];
int res[1009];
int n,tot;
const int INF = 1e9+7;
int cntbit(int n){
	return n == 0 ? 0 : cntbit(n >> 1) + 1;
}
vector<int>a;
void ask(){
	for(int i = 1; i <= n; i++)
		ans[tot][i] = INF;
	if((int)a.size() == 0){
		tot++;
		return;
	}
	int sz = a.size();
	printf("%d\n",sz);
	for(int i = 0; i < sz; i++){
		if(i == sz - 1)
			printf("%d\n",a[i]);
		else
			printf("%d ",a[i]);
	}
	fflush(stdout);
	for(int i = 1; i <= n; i++)
		scanf("%d",&ans[tot][i]);
	tot++;
	return;
}

int main(){
	scanf("%d",&n);
	int m = cntbit(n);
	for(int i = 0; i < m; i++){
		a.clear();
		for(int j = 1; j <= n; j++){
			if(((1 << i) & j)==0){
				a.push_back(j);
			}
		}	
		ask();
		a.clear();
		for(int j = 1; j <=n; j++){
			if(((1<<i)&j))
				a.push_back(j);
		}
		ask();
	}
	printf("-1\n");
	for(int i=1;i<=n;i++)res[i]=INF;
	for(int i=0;i<m;i++){
		for(int j=1;j<=n;j++){
			if(j&(1<<i)){
				res[j]=min(res[j],ans[2*i][j]);
			}
			else{
				res[j]=min(res[j],ans[2*i+1][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==n)
			printf("%d\n",res[i]);
		else
			printf("%d ",res[i]);
	}
	fflush(stdout);
	//system("pause");
	return 0;
}