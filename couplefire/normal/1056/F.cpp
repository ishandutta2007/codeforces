#include<bits/stdc++.h>
#define S(x) ((x)*(x))
using namespace std;
inline int read()
{
    int f=1,w=0;char x=0;
    while(x<'0'||x>'9') {if(x=='-') f=-1; x=getchar();}
    while(x!=EOF&&x>='0'&&x<='9') {w=(w<<3)+(w<<1)+(x^48);x=getchar();}
    return w*f;
}
const int N=1010;
int n;
double C,Tim,c[N],f[N][N];
struct Prob{int a,p;} s[N];
inline bool cmp(Prob x,Prob y) {return x.a>y.a;}
int main(){
	int T;scanf("%d",&T);
	c[0]=1;for(int i=1;i<=101;i++) c[i]=c[i-1]*10/9;
	while(T--)
	{
		scanf("%d%lf%lf",&n,&C,&Tim);
		for(int i=1;i<=n;i++) s[i].a=read(),s[i].p=read();
		sort(s+1,s+n+1,cmp);
		for(int i=0;i<101;++i)
            for(int j=0;j<1010;++j)
                f[i][j]=1e18;
		f[0][0]=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j;j--)
				for(int k=s[i].p;k<=10*i;k++)
					f[j][k]=min(f[j][k],f[j-1][k-s[i].p]+s[i].a*c[j]);
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=ans+1;j<=10*i;j++)
			{
				double l=0,r=Tim;
				while(r-l>1e-5)
				{
					double L=l+(r-l)/3,R=r-(r-l)/3;
					if(L+f[i][j]/(1+C*L)>R+f[i][j]/(1+C*R)) l=L;
					else r=R;
				}
				l=(l+r)/2;
				if(l+f[i][j]/(1+C*l)+10*i<Tim) ans=j;
			}
		printf("%d\n",ans);
	}
}