#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define maxn 200005
using namespace std;

int T,n,i,j,k,s[maxn],B,tot,cnt,bz[maxn];
vector<int> a[maxn],d[maxn];
struct arr{int x,i,j;} A[maxn];
int cmp(arr a,arr b){return a.x<b.x;}

void doit(){
	scanf("%d",&n),tot=0;
	for(i=1;i<=n;i++){
		scanf("%d",&s[i]),a[i].clear();
		for(j=1;j<=s[i];j++) {
			scanf("%d",&k),a[i].push_back(k);
			tot++,A[tot].x=k,A[tot].i=i,A[tot].j=j-1;
		}
	}
	sort(A+1,A+1+tot,cmp),cnt=0;
	for(i=1;i<=tot;i++){
		if (i==0||A[i].x!=A[i-1].x) cnt++,bz[cnt]=0,d[cnt].clear();
		a[A[i].i][A[i].j]=cnt;
	}
	for(i=1;i<=n;i++) if (s[i]>=B){
		for(j=0;j<s[i];j++) bz[a[i][j]]=1;
		for(j=1;j<=n;j++) if (j!=i){
			int c=0;
			for(k=0;k<s[j];k++) 
				c+=bz[a[j][k]];
			if (c>=2) {
				if (i>j) swap(i,j);
				printf("%d %d\n",i,j);
				return;
			}
		}
		for(j=0;j<s[i];j++) bz[a[i][j]]=0;
	}
	for(i=1;i<=n;i++) if (s[i]<B) 
		for(j=0;j<s[i];j++) d[a[i][j]].push_back(i);
	for(i=1;i<=cnt;i++){
		for(j=0;j<d[i].size();j++) {
			int x=d[i][j];
			for(k=0;k<s[x];k++) if (a[x][k]!=i){
				if (bz[a[x][k]]) {
					j=bz[a[x][k]];
					if (x>j) swap(x,j);
					printf("%d %d\n",x,j);
					return;
				}
				bz[a[x][k]]=x;
			}
		}
		for(j=0;j<d[i].size();j++) {
			int x=d[i][j];
			for(k=0;k<s[x];k++) bz[a[x][k]]=0;
		}
	}
	printf("-1\n");
}

int main(){
	scanf("%d",&T),B=300;
	while (T--) doit();
}