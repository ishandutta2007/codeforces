#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 1005
#define ll long long 
using namespace std;

int T,n,m,i,j,k,a[maxn],d[maxn],w;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		w=0,d[w]=-1;
		for(i=1;i<=n;i++){
			while (a[i]!=d[w]+1&&a[i]!=1) w--;
			if (a[i]==1) w++,d[w]=1;
			else d[w]++;
			for(j=1;j<w;j++) printf("%d.",d[j]);
			printf("%d\n",d[j]);
		}
	}
}