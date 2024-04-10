#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define maxn 250005
using namespace std;

int n,m,i,j,k,f[maxn];
vector<int> a[maxn];

void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

int d[5],c[maxn];
void check(){
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=m;j++) cnt+=a[i][j]!=c[j];
		if (cnt>2) return;
	}
	printf("Yes\n");
	for(int i=1;i<=m;i++) printf("%d ",c[i]);
	exit(0);
}

void check0(int mid){
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=m;j++) cnt+=a[i][j]!=c[j];
		if (cnt>2) {
			if (!c[mid]) c[mid]=a[i][mid],cnt--;
			if (cnt>2) return;
		}
	}
	printf("Yes\n");
	if (c[mid]==0) c[mid]=1;
	for(int i=1;i<=m;i++) printf("%d ",c[i]);
	exit(0);
}


int main(){
	read(n),read(m);
	for(i=1;i<=n;i++) {
		a[i].push_back(0);
		for(j=1;j<=m;j++) read(k),a[i].push_back(k);
	}
	int mx=0;
	for(i=2;i<=n;i++) {
		for(j=1;j<=m;j++) f[i]+=a[i][j]!=a[1][j];
		if (f[i]>4) printf("No\n"),exit(0);
		mx=max(mx,f[i]);
	}
	if (mx<=2) {
		printf("Yes\n");
		for(i=1;i<=m;i++) printf("%d ",a[1][i]);
		return 0;
	}
	if (mx==3){
		for(k=2;k<=n;k++) if (f[k]==3) break;
		for(i=1;i<=m;i++) if (a[1][i]!=a[k][i]) d[++d[0]]=i;
			else c[i]=a[1][i];
		for(int t1=0;t1<2;t1++) {
			c[d[1]]=(t1)?a[k][d[1]]:a[1][d[1]];
			for(int t2=0;t2<2;t2++){
				c[d[2]]=(t2)?a[k][d[2]]:a[1][d[2]];
				for(int t3=0;t3<2;t3++){
					c[d[3]]=(t3)?a[k][d[3]]:a[1][d[3]];
					check();
				}
			}
		}
		for(i=1;i<=3;i++) for(j=1;j<=3;j++) if (i!=j){
			c[d[i]]=a[1][d[i]],c[d[j]]=a[k][d[j]],c[d[6-i-j]]=0;
			check0(d[6-i-j]);
		}
		printf("No\n");
		return 0;
	}
	if (mx==4){
		for(k=2;k<=n;k++) if (f[k]==4) break;
		for(i=1;i<=m;i++) if (a[1][i]!=a[k][i]) d[++d[0]]=i;
		for(i=1;i<=m;i++) c[i]=a[1][i];
		for(i=1;i<=3;i++) for(j=i+1;j<=4;j++){
			for(int t=1;t<=4;t++) if (t==i||t==j) c[d[t]]=a[1][d[t]];
				else c[d[t]]=a[k][d[t]];
			check();
		}
		printf("No\n");
		return 0;
	}
}