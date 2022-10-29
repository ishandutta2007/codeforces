#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
using namespace std;

int n,i,j,k,a[maxn][2],ans,p[maxn*2],mx,mi,d[2][maxn],cnt,sum,bz[maxn];
int A(int i,int j){return (a[i][0]==j)?a[i][1]:a[i][0];}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&a[i][0],&a[i][1]);
		p[a[i][0]]=p[a[i][1]]=i;
	}
	mi=0,mx=2*n+1;
	while (mi+1<mx){
		mx--,cnt=a[p[mx]][1]!=mx,sum=1;
		d[0][0]=d[1][0]=0;
		d[0][++d[0][0]]=A(p[mx],mx);
		if (bz[p[mx]]) printf("-1"),exit(0);
		bz[p[mx]]=1;
		int now=0;
		while (d[now][0]){
			for(i=2;i<=d[now][0];i++)
				if (now==0&&d[now][i-1]>d[now][i]||now==1&&d[now][i-1]<d[now][i])
					printf("-1"),exit(0);
			if (now==0){
				k=now^1;
				d[k][0]=0;
				for(i=1;i<=d[now][0];i++){
					while (mi+1<d[now][i]) {
						mi++,sum++,cnt+=a[p[mi]][1]!=mi;
						if (bz[p[mi]]) printf("-1"),exit(0);
						bz[p[mi]]=1;
						d[k][++d[k][0]]=A(p[mi],mi);
					}
					mi++;
				}
			} else {
				k=now^1;
				d[k][0]=0;
				for(i=1;i<=d[now][0];i++){
					while (mx-1>d[now][i]) {
						mx--,sum++,cnt+=a[p[mx]][1]!=mx;
						if (bz[p[mx]]) printf("-1"),exit(0);
						bz[p[mx]]=1;
						d[k][++d[k][0]]=A(p[mx],mx);
					}
					mx--;
				}
			}
			now^=1;
		}
		ans+=min(cnt,sum-cnt);
	}
	printf("%d\n",ans);
}