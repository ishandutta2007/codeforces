#include<cstdio>
#include<cstring> 
#define MN 1000000
#define MOD 1000000007
char S[MN+5],T[MN+5];
int c[MN+5][26],l[MN+5],f[MN+5],tn,df[MN+5],ff[MN+5],s[MN+5],F[MN+5];
int main()
{
	int n,i,j,x;
	scanf("%s",S+1);n=strlen(S+1);
	T[0]=255;for(i=1;i<=n/2;++i)T[2*i-1]=S[i]-'a',T[2*i]=S[n-i+1]-'a';
	f[0]=1;l[++tn]=-1;
	for(F[0]=i=x=1;i<=n;++i)
	{
		while(T[i]!=T[i-l[x]-1])x=f[x];
		if(!c[x][T[i]])
		{
			for(j=f[x];T[i-l[j]-1]!=T[i];j=f[j]);
			f[++tn]=c[j][T[i]];
			l[c[x][T[i]]=tn]=l[x]+2;
			df[tn]=l[tn]-l[f[tn]];
			ff[tn]=df[tn]==df[f[tn]]?ff[f[tn]]:tn;
		}
		x=c[x][T[i]];
		for(j=x;j;j=f[ff[j]])
		{
			s[j]=F[i-l[ff[j]]];
			if(ff[j]!=j)s[j]=(s[j]+s[f[j]])%MOD;
			if(~i&1)F[i]=(F[i]+s[j])%MOD;
		}
	}
	printf("%d",F[n]);
}