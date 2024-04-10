#include <cstdio>
#include <iostream>
#include <algorithm>
#include <bitset>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
struct mat{
	std::bitset<32> v[505][17];
}a[60][2],cur,tmp;int n,m,x,y,z,sg=0,fl;long long ans=0;
mat operator*(mat a,mat b){
	mat res;
	rpt(i,1,n) rpt(j,1,16){
		res.v[i][j]=0;
		rpt(k,1,n) if(a.v[i][(k-1)/32+1][(k-1)%32]) res.v[i][j]|=b.v[k][j];
	}
	return res;
}
void print(mat a){
	rpt(i,1,n){
		rpt(j,1,n) printf("%d",(int)a.v[i][(j-1)/32+1][(j-1)%32]);
		printf("\n");
	}
	printf("\n");
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%d",&x,&y,&z);
		a[0][z].v[x][(y-1)/32+1][(y-1)%32]=1;
	}
	rpt(i,1,59) rpt(j,0,1) a[i][j]=a[i-1][j]*a[i-1][!j];
	rpt(i,1,n) cur.v[i][(i-1)/32+1][(i-1)%32]=1;
	rpd(i,59,0){
		tmp=cur*a[i][sg];fl=0;
		rpt(j,1,n) if(tmp.v[1][(j-1)/32+1][(j-1)%32]){
			fl=1;break;
		}
		if(fl) ans|=1ll<<i,sg^=1,cur=tmp;
	}
	if(ans>1000000ll*1000000*1000000) printf("-1\n");
	else printf("%I64d\n",ans);
}