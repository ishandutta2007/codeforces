#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=220000;
char pool[MX],*pc=pool;
char* New(int n){pc+=n;return pc-n;}

int N,Len;
char S[MX],tmp[MX];
int len[MX];
char *T[MX];

int C[MX][26],F[MX],V[MX],ac=1;
queue<int> Q;
void Ins(char* s,int l)
{
	int x=1;
	Fr(i,1,l)
	{
		int k=s[i]-'a';
		if(!C[x][k])C[x][k]=++ac;
		x=C[x][k];
	}
	++V[x];
}
void Build()
{
	Fo(k,0,26)C[0][k]=1;
	Q.push(1);
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		V[x]+=V[F[x]];
		Fo(k,0,26)
			if(C[x][k])F[C[x][k]]=C[F[x]][k],Q.push(C[x][k]);
			else C[x][k]=C[F[x]][k];
	}
}

int L[MX],R[MX];
void SolveL()
{
	Fr(i,1,N)Ins(T[i],len[i]);
	Build();int x=1;
	Fr(i,1,Len)i[L]=(x=C[x][S[i]-'a'])[V];
}
void SolveR()
{
	Fr(i,0,ac)
	{
		memset(C[i],0,26*sizeof(int));
		F[i]=V[i]=0;
	}
	ac=1;
	
	Fr(i,1,N)reverse(T[i]+1,T[i]+len[i]+1),Ins(T[i],len[i]);
	Build();int x=1;
	Fl(i,Len,1)R[i]=V[x=x[C][i[S]-'a']];
}

int main()
{
	scanf("%s%d",S+1,&N);
	Len=strlen(S+1);
	Fr(i,1,N)
	{
		scanf("%s",tmp);
		len[i]=strlen(tmp);
		T[i]=New(len[i]);
		memcpy(T[i],tmp,len[i]);
		--T[i];
	}
	//Fr(i,1,N)printf("%s\n",T[i]+1);
	SolveL(),SolveR();
//	Fr(i,1,Len)printf("%d ",L[i]);putchar('\n');
//	Fr(i,1,Len)printf("%d ",R[i]);putchar('\n');
	ll ans=0;
	Fo(i,1,Len)ans+=1ll*L[i]*R[i+1];
	printf("%lld\n",ans);
	return 0;
}