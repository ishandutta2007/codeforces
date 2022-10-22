#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=70;
int N;
char S[MX];

bool Check(int A,int B,int C)
{
	int tp=0;
	Fr(i,1,N)
	{
		char ch=S[i],x=0;
		switch(ch)
		{
		case 'A':x=A;break;
		case 'B':x=B;break;
		case 'C':x=C;break;
		}
		if(x)++tp;
		else
		{
			if(tp==0)return 0;
			--tp;
		}
	}
	return tp==0;
}

int mian()
{
	scanf("%s",S+1),N=strlen(S+1);
	Fr(A,0,1)Fr(B,0,1)Fr(C,0,1)
		if(Check(A,B,C)){return 1;}
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r=mian();
		if(r)printf("YES\n");
		else printf("NO\n");
		Fill(S,0);
	}
	return 0;
}