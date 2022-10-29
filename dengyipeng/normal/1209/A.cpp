#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 105
using namespace std;

int n,a[maxn],i,j,k,bz[maxn];

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int cnt=0;
	for(i=1;i<=n;i++) if (!bz[i]){
		cnt++;
		for(j=i+1;j<=n;j++)
			if (a[j]%a[i]==0)
				bz[j]=1;
	}
	printf("%d",cnt);
}