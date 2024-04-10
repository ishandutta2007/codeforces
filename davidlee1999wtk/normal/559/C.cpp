#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
#define P 1000000007
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL ksm(int a,LL b)
{
    LL c=1,d=a;
    while(b)
    {
        if(b&1)
            c=(c*d)%P;
        d=(d*d)%P;
        b>>=1;
    }
    return c;
}

inline void upd(int &x,int y)
{
	x+=y;
	if(x>=P) x-=P;
}

int jc[N],ny[N];
int C(int n,int m)
{
	if(m>n||m<0) return 0;
	return (LL)jc[n]*ny[m]%P*ny[n-m]%P;
}
pii p[2005];
int dp[2005][2];
int main()
{
	int i,h,w,n=200000,j,k;
	jc[0]=ny[0]=1;
	for(i=1;i<=n;i++)
		jc[i]=jc[i-1]*(LL)i%P;
	ny[n]=ksm(jc[n],P-2);
	for(i=n;i;i--)
		ny[i-1]=(LL)ny[i]*i%P;
	//debug(ny[2]);
	cin>>h>>w>>n;
	dp[0][1]=1;
	p[0].fi=1,p[0].se=1;
	for(i=1;i<=n;i++)
		scanf("%d%d",&p[i].fi,&p[i].se);
	n++;
	p[n].fi=h,p[n].se=w;
	sort(p+1,p+1+n);
	for(i=1;i<=n;i++)
		for(j=n-1;j>=0;j--)
			for(k=0;k<=1;k++)
				upd(dp[i][k^1],(LL)dp[j][k]*C(p[i].fi-p[j].fi+p[i].se-p[j].se,p[i].fi-p[j].fi)%P);
	cout<<(dp[n][0]-dp[n][1]+P)%P<<endl;
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);