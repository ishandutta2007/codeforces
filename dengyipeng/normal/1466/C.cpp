#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 100005
using namespace std;

int T,n,i,j,k,a[maxn],cnt,bz[26];

int main(){
	scanf("%d",&T);
	char ch=getchar();
	while (T--){
		while (ch<'a'||ch>'z') ch=getchar();
		n=0,cnt=0;
		while (ch>='a'&&ch<='z') a[++n]=ch-'a',ch=getchar();
		for(i=1;i<=n;i++) if (i>1&&i<n&&a[i-1]==a[i+1]||i<n&&a[i]==a[i+1]){
			for(j=0;j<26;j++) {
				if (j==a[i]) continue;
				if (i>1&&j==a[i-1]) continue;
				if (i+1<n&&j==a[i+2]) continue;
				if (i+2<n&&j==a[i+3]) continue;
				a[i+1]=j;
				break;
			}
			cnt++;
		}
		printf("%d\n",cnt);
	}
}