#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#define maxn 300005
using namespace std;

int T,n,i,j,k,a[3][maxn],c[3][2],cnt[maxn];

void doit(){
	for(int p=0;p<3;p++) for(int q=p+1;q<3;q++) for(int x=0;x<2;x++)
		if (min(c[p][x],c[q][x])>=n) {
			memset(cnt,0,sizeof(int)*(3*n+1));
			int now=1;
			for(i=1;i<=2*n;i++){
				j=i;
				while (a[p][j]!=x&&j<=2*n) j++;
				cnt[now]=max(cnt[now],j-i),now++,i=j;
			}
			now=1;
			for(i=1;i<=2*n;i++){
				j=i;
				while (a[q][j]!=x&&j<=2*n) j++;
				cnt[now]=max(cnt[now],j-i),now++,i=j;
			}
			for(i=1;i<=max(c[p][x],c[q][x])+1;i++){
				for(j=1;j<=cnt[i];j++) putchar('0'+(x^1));
				if (i<=max(c[p][x],c[q][x])) putchar('0'+x);
			}
			putchar('\n');
			return;
		}
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		char ch=getchar();
		memset(c,0,sizeof(c));
		for(i=0;i<3;i++){
			while (ch<'0'||ch>'1') ch=getchar();
			for(j=1;j<=2*n;j++) a[i][j]=ch-'0',ch=getchar(),c[i][a[i][j]]++;
		}
		doit();
	}
}