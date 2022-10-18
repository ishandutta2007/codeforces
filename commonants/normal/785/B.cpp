#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
const int MX=200111;
int n,m;
int l[MX],r[MX],l2[MX],r2[MX];
int mxl,mnr,mxl2,mnr2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&l2[i],&r2[i]);
	mnr=mnr2=0x3f3f3f3f;
	for(int i=1;i<=n;i++)mxl=max(mxl,l[i]),mnr=min(mnr,r[i]);
	for(int i=1;i<=m;i++)mxl2=max(mxl2,l2[i]),mnr2=min(mnr2,r2[i]);
	int ans=0;
	ans=max(ans,mxl2-mnr);
	ans=max(ans,mxl-mnr2);
	printf("%d\n",ans);
	return 0;
}