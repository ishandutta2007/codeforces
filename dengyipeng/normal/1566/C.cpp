#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100005
using namespace std;

int T,n,i,j,k,a[maxn][2],c[3];
int mex(){int k=0; while (k<=2&&c[k]) k++; return k;}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		char ch=getchar();
		while (ch<'0'||ch>'2') ch=getchar(); n=0;
		while (ch>='0'&&ch<='2') a[++n][0]=ch-'0',ch=getchar();
		while (ch<'0'||ch>'2') ch=getchar(); n=0;
		while (ch>='0'&&ch<='2') a[++n][1]=ch-'0',ch=getchar();
		int ans=0; c[0]=c[1]=c[2]=0;
		for(i=1;i<=n;i++){
			if (a[i][0]==0||a[i][1]==0){
				if (c[0]) {
					j=i-1,k=mex();
					while (1){
						c[a[j][0]]--,c[a[j][1]]--;
						if (mex()!=k) break; else j--;
					}
					ans+=k,c[0]=c[1]=c[2]=0,j++;
					while (j<=i)
						c[a[j][0]]++,c[a[j][1]]++,j++;
				} else c[a[i][0]]++,c[a[i][1]]++;
			} else c[a[i][0]]++,c[a[i][1]]++;
		}
		ans+=mex();
		printf("%d\n",ans);
	}
}