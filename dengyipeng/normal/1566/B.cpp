#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;

int T,n,i,j,k,a[maxn];
	
int main(){
	scanf("%d",&T);
	while (T--){
		n=0; char ch=getchar();
		while (ch<'0'||ch>'9') ch=getchar();
		while (ch>='0'&&ch<='9') {
			if (!n||a[n]!=ch-'0')
				a[++n]=ch-'0';
			ch=getchar();
		}
		int c=0,t=0;
		for(i=1;i<=n;i++){
			if (a[i]==0) c+=t^1,t=1; else 
			if (a[i]==1) t=0;
		}
		if (c<=2) {printf("%d\n",c);continue;}
		c=0,t=0;
		for(i=1;i<=n;i++){
			if (a[i]==0) c+=t^1,t=1; else 
			if (a[i]==2) t=0;
		}
		if (c<=1) printf("2\n"); else printf("3\n");
	}
}