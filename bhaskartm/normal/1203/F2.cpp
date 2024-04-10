#include <bits/stdc++.h>
using namespace std;
const int M=60001;
int n,r,P,Q,a,f[M];
struct O{int x,y;}p[105],q[105];
bool cmp1(O A,O B){return A.x<B.x;}
bool cmp2(O A,O B){return A.x+A.y>B.x+B.y;}
int main(){
	scanf("%d%d",&n,&r);
	for (int x,y,i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if (y>=0) p[++P]=(O){x,y};
		else q[++Q]=(O){x,y};
	}
	sort(p+1,p+P+1,cmp1);
	sort(q+1,q+Q+1,cmp2);
	for (int i=1;i<=P;i++)
		if (r>=p[i].x) a++,r+=p[i].y;
	memset(f,0x8f,sizeof f);f[r]=a;
	for (int i=1;i<=Q;i++)
		for (int j=q[i].x;j<M;j++)
			if (j+q[i].y>=0)
				f[j+q[i].y]=max(f[j+q[i].y],f[j]+1);
	for (int i=1;i<M;i++) f[0]=max(f[0],f[i]);
	return printf("%d\n",f[0]),0;
}