#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
#define f09(i) rep(i,10)
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
const int L=100500;
const int N=10;
char s[L];
int cnt[N],p[N],n,l;
int getc(int i)
{
	int num=0,have=0;
	f09(j) f09(k) if(abs(k-i)==j){
		int a=cnt[k];
		if(j==0) a+=p[k];
		if(have+a>=l) a=l-have;
		have+=a;
		num+=a*j;
	}
	return ((have<l)?L:num);
}
int getans()
{
	int ans=L;
	f09(i)
	ans=min(ans,getc(i));
	return ans;
}
int main()
{
	scanf("%d%d",&n,&l);
	gets(s);gets(s);
	rep(i,n) cnt[s[i]-'0']++;
	int ans=getans();
	printf("%d\n",ans);
	rep(i,n)
	{
		cnt[s[i]-'0']--;
		f09(v)
		{
			p[v]++;
			int tmp=getans();
			if(tmp+abs(s[i]-'0'-v)==ans)
			{
				ans=tmp;
				s[i]=v+'0';
				break;
			}
			p[v]--;
		}
	}
	puts(s);
	return 0;
}