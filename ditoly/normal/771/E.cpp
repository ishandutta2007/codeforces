#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define ll long long
char B[1<<26],*S=B,C;ll X,F;
inline ll read()
{
	for(F=1;(C=*S++)<'0'||C>'9';)if(C=='-')F=-1;
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X*F;
}
#define MN 300000
#define d(x,y) make_pair(x,y)
ll s[MN+5][3];
int t[MN+5][3],f[MN+5];
map<ll,int> mp;
map<pair<int,int>,int> u,ff;
int cal(int x,int y)
{
	if(u[d(x,y)])return ff[d(x,y)];
	return u[d(x,y)]=1,ff[d(x,y)]=max(f[min(x,y)],t[x][0]>t[y][1]?cal(t[x][0],y)+1:cal(x,t[y][1])+1);
}
int main()
{
	fread(B,1,1<<26,stdin);
	int n=read()+1,i,j,k,l;
	for(i=2;i<=n;++i)s[i][0]=s[i-1][0]+read();
	for(i=2;i<=n;++i)s[i][1]=s[i-1][1]+read(),s[i][2]=s[i][0]+s[i][1];
	for(l=0;l<3;++l)for(mp.clear(),i=1;i<=n;++i)t[i][l]=max(t[i-1][l],mp[s[i][l]]),mp[s[i][l]]=i;
	f[0]=t[0][0]=t[0][1]=-1;u[d(0,0)]=1;ff[d(0,0)]=-2;
	for(i=2;i<=n;++i)f[i]=max(f[t[i][2]]+1,cal(i,i)),ff[d(i,i)]=f[i];
	printf("%d",f[n]);
}