#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;
#define ll unsigned long long
#define MN 2000
#define ML 600
bitset<MN+5> b[MN+5],c[MN+5],x,y;
vector<int> ans;
char s[ML+5];
ll z[32];int zn;
int main()
{
	int n,m,l,i,j;
	scanf("%d",&n);
	for(l=0;l<n;++l)
	{
		scanf("%s",s+1);m=strlen(s+1);
		memset(z,zn=0,sizeof(z));
		for(i=m;i>0;i-=19,++zn)for(j=max(i-18,1);j<=i;++j)z[zn]=z[zn]*10+s[j]-'0';
		for(x.reset(),i=0;;++i)
		{
			x[i]=z[0]&1;z[0]>>=1;
			if(zn==1&&!z[0])break;
			for(j=1;j<zn;++j)z[j]&1?z[j-1]+=(ll)5e18:0,z[j]>>=1;
			if(!z[zn-1])--zn;
		}
		y.reset();y[l]=1;
		for(i=MN;i>=0;--i)if(x[i])if(!b[i].count()){b[i]=x;c[i]=y;break;}else x^=b[i],y^=c[i];
		if(i>=0){puts("0");continue;}
		ans.clear();
		for(i=0;i<l;++i)if(y[i])ans.push_back(i);
		printf("%d ",ans.size());for(j=0;j<ans.size();++j)printf("%d ",ans[j]);puts("");
	}
}