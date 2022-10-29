#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 1000005
using namespace std;

int T,n,i,j,k,a,b,c,p[maxn];
char ch;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d%d",&n,&a,&b,&c);
		for(ch=getchar();ch!='R'&&ch!='P'&&ch!='S';ch=getchar());
		int cnt=0;
		for(i=1;i<=n;i++) {
			if (ch=='R'&&b) cnt++,b--,p[i]=2; else 
			if (ch=='P'&&c) cnt++,c--,p[i]=3; else
			if (ch=='S'&&a) cnt++,a--,p[i]=1; else 
				p[i]=0;
			ch=getchar();
		}
		if (cnt>=(n+1)/2) {
			printf("YES\n");
			for(i=1;i<=n;i++) {
				if (p[i]==1||!p[i]&&a>0) printf("R"),a-=!p[i]; else 
				if (p[i]==2||!p[i]&&b>0) printf("P"),b-=!p[i]; else 
				if (p[i]==3||!p[i]&&c>0) printf("S"),c-=!p[i];
			}
			printf("\n");
		}
		else printf("NO\n");
	}
}