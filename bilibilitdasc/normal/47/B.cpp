#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int main()
{
	int l[3],r[3],p[3],np[3],fp[3];
	rep(i,3)
	{
		char a,b,c;
		cin>>a>>b>>c;
		if(b=='>') a^=c^=a^=c;
		l[i]=a-'A';
		r[i]=c-'A';
		p[i]=i;
	}
	int n=0;
	do
	{
		int notz=0;
		rep(i,3) np[p[i]]=i;
		rep(i,3) notz+=(np[l[i]]>np[r[i]]);
		if(notz==0)
		{
			n++;
			memcpy(fp,p,sizeof(fp));
		}
	}
	while(next_permutation(p,p+3));
	if(n==1)
	{
		rep(i,3) cout<<(char)(fp[i]+'A');
		cout<<endl;
	}
	else
	prt("Impossible");
	return 0;
}
/*
A>B
C<B
A>C

A<B
B>C
C>A

A>C
C>B
A<B

A>C
B>A
B>C

A>C
B<A
B<C 
*/