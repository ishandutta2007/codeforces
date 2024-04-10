#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 3000
using namespace std;
int n1,n2,n3,c1[30],c2[30],c3[30],cc[30],c12[30],c23[30],c13[30];char s1[N+5],s2[N+5],s3[N+5];
int t,sx[N+5],sy[N+5],d1[30],d2[30],d3[30];
int main()
{
	RI i,j,k,p;scanf("%s%s%s",s1+1,s2+1,s3+1);
	n1=strlen(s1+1),n2=strlen(s2+1),n3=strlen(s3+1);
	for(i=1;i<=n1;++i) ++c1[s1[i]&31];for(i=1;i<=n2;++i) ++c2[s2[i]&31];for(i=1;i<=n3;++i) ++c3[s3[i]&31];
	for(i=1;i<=26;++i)
	{
		cc[i]=min(c1[i],min(c2[i],c3[i])),c1[i]-=cc[i],c2[i]-=cc[i],c3[i]-=cc[i];
		c12[i]=min(c1[i],c2[i]),c1[i]-=c12[i],c2[i]-=c12[i];
		c13[i]=min(c1[i],c3[i]),c1[i]-=c13[i],c3[i]-=c13[i];
		c23[i]=min(c2[i],c3[i]),c2[i]-=c23[i],c3[i]-=c23[i];
	}
	RI g1=0,g2=0,g3=0;for(i=1;i<=26;++i) g1+=c1[i]-c23[i],g2+=c2[i]-c13[i],g3+=c3[i]-c12[i];
	g1=max(g1,0),g2=max(g2,0),g3=max(g3,0);RI f=0,g=min(g1,min(g2,g3));
	for(i=1;i<=26;++i) W(f<g&&cc[i]&&c1[i]) --cc[i],--c1[i],++d1[i],++f;
	for(i=1;i<=26;++i) W(f<g&&cc[i]&&c2[i]) --cc[i],--c2[i],++d2[i],++f;
	for(i=1;i<=26;++i) W(f<g&&cc[i]&&c3[i]) --cc[i],--c3[i],++d3[i],++f;
	for(i=1;i<=26;++i) for(j=1;j<=26;++j) for(k=1;k<=26;++k)
		W(d1[i]&&c2[j]&&c3[k]) --d1[sx[++t]=i],--c2[sy[t]=j],sx[++t]=i,--c3[sy[t]=k];
	for(i=1;i<=26;++i) for(j=1;j<=26;++j) for(k=1;k<=26;++k)
		W(d2[i]&&c1[j]&&c3[k]) --d2[sx[++t]=i],--c1[sy[t]=j],sx[++t]=i,--c3[sy[t]=k];
	for(i=1;i<=26;++i) for(j=1;j<=26;++j) for(k=1;k<=26;++k)
		W(d3[i]&&c1[j]&&c2[k]) --d3[sx[++t]=i],--c1[sy[t]=j],sx[++t]=i,--c2[sy[t]=k];
	g1-=f,g2-=f,g3-=f;
	for(p=1;p<=26;++p) W(cc[p]>=2&&g1&&g2&&g3)
	{
		for(i=1;i<=26;++i) if(c1[i]) for(j=1;j<=26;++j) if(c2[j]) for(k=1;k<=26;++k) if(c3[k])
			{cc[p]-=2,sx[++t]=p,--c1[sy[t]=i],sx[++t]=p,--c2[sy[t]=j],sx[++t]=p,--c3[sy[t]=k],--g1,--g2,--g3;goto D;}D:;
	}
	for(i=1;i<=26;++i) for(j=1;j<=26;++j)
	{
		W(c12[i]&&c3[j]) --c12[sx[++t]=i],--c3[sy[t]=j];
		W(c13[i]&&c2[j]) --c13[sx[++t]=i],--c2[sy[t]=j];
		W(c23[i]&&c1[j]) --c23[sx[++t]=i],--c1[sy[t]=j];
	}
	for(i=1;i<=26;++i) for(j=1;j<=26;++j) for(k=1;k<=26;++k)
	{
		W(c12[i]&&c13[j]&&c23[k]) sx[++t]=i,sy[t]=j,sx[++t]=i,sy[t]=k,--c12[i],--c13[j],--c23[k];
	}
	for(i=1;i<=26;++i)
	{
		W(c12[i]) --c12[sx[++t]=i];
		W(c13[i]) --c13[sx[++t]=i];
		W(c23[i]) --c23[sx[++t]=i];
	}
	W((g1>0)+(g2>0)+(g3>0)>=2)
	{
		if(g1>=g3&&g2>=g3) for(i=1;i<=26;++i) for(j=1;j<=26;++j) if(c1[i]&&c2[j]) {--c1[sx[++t]=i],--c2[sy[t]=j],--g1,--g2;goto E;}
		if(g1>=g2&&g3>=g2) for(i=1;i<=26;++i) for(j=1;j<=26;++j) if(c1[i]&&c3[j]) {--c1[sx[++t]=i],--c3[sy[t]=j],--g1,--g3;goto E;}
		if(g2>=g1&&g3>=g1) for(i=1;i<=26;++i) for(j=1;j<=26;++j) if(c2[i]&&c3[j]) {--c2[sx[++t]=i],--c3[sy[t]=j],--g2,--g3;goto E;}E:;
	}
	for(i=1;i<=26;++i) W(cc[i]) --cc[sx[++t]=i];
	for(i=1;i<=26;++i) W(c1[i]) --c1[sx[++t]=i];
	for(i=1;i<=26;++i) W(c2[i]) --c2[sx[++t]=i];
	for(i=1;i<=26;++i) W(c3[i]) --c3[sx[++t]=i];
	for(printf("%d\n",t),i=1;i<=t;++i) printf("%c%c\n",(char)(64|sx[i]),sy[i]?(char)(64|sy[i]):'A');return 0;
}