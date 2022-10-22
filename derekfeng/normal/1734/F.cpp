#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tc;ll n,m;
ll f[64][2][2][2];
void sol(){
	memset(f,0,sizeof(f));
	scanf("%lld%lld",&n,&m);m--;
	f[0][0][0][0]=1;
	for(int t=1;t<62;t++){
		int p=(n>>(t-1))&1;
		int q=(m>>(t-1))&1;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++){
			if(f[t-1][i][j][k])for(int c=0;c<2;c++){
				int nc=p+c+j,ni=i,nj=0,nk;
				if(nc>1)nc-=2,nj=1;
				ni^=(nc!=c);
				if(c>q)nk=1;
				else if(c<q)nk=0;
				else nk=k;
				f[t][ni][nj][nk]+=f[t-1][i][j][k];
			}
		}
	}
	printf("%lld\n",f[61][1][0][0]);
}
int main(){
	scanf("%d",&tc);while(tc--)sol();
}