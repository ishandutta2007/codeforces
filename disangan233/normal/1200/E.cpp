// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define re register int
#define uint unsigned int
#define db double
#define in inline
const int N=1e5+5;
int n,tol,len[N];
string s[N];
ll pw1[N*20],pw2[N*20];
uint cas1,cas2,p1,p2;
vector<ll>h1[N],h2[N];
in ll random(ll x,ll y) {return (ll)rand()*rand()%(y-x+1)+x;}
int main()
{
	ios::sync_with_stdio(false);srand(time(0));p1=random(100000000,UINT_MAX);cas1=random(131,UINT_MAX);
	p2=random(1000000000,UINT_MAX);cas2=random(131,UINT_MAX);
	cin>>n;pw1[0]=pw2[0]=1;
	for(re i=1;i<=n;i++) cin>>s[i],s[i]=' '+s[i],len[i]=s[i].length(),tol+=len[i];
	for(re i=1;i<=tol;i++) pw1[i]=pw1[i-1]*cas1%p1,pw2[i]=pw2[i-1]*cas2%p2;
	for(re i=1;i<=n;i++)
	{
		ll nh1=0,nh2=0;h1[i].push_back(0);h2[i].push_back(0);
		for(re j=1;j<len[i];j++) nh1=nh1*cas1%p1+s[i][j],nh1%=p1,h1[i].push_back(nh1);
		for(re j=1;j<len[i];j++) nh2=nh2*cas2%p2+s[i][j],nh2%=p2,h2[i].push_back(nh2);
	}
	for(re i=1;i<len[1];i++) cout<<s[1][i];
	for(re i=2;i<=n;i++)
	{
		re j;
		for(j=min(len[i]-1,len[1]-1);j;j--)
		{
			ll pre1=(h1[1][len[1]-1]+p1-h1[1][len[1]-1-j]*pw1[j]%p1)%p1;pre1=(pre1+p1)%p1;
			ll nw1=h1[i][j];
			if(pre1!=nw1) continue;
			ll pre2=(h2[1][len[1]-1]+p2-h2[1][len[1]-1-j]*pw2[j]%p2)%p2;pre2=(pre2+p2)%p2;
			ll nw2=h2[i][j];
			if(pre2==nw2) break;
		}
		ll tmp1=h1[1][len[1]-1],tmp2=h2[1][len[1]-1];
		for(re k=j+1;k<len[i];k++) 
		{
			tmp1=tmp1*cas1%p1+s[i][k],tmp1%=p1;tmp2=tmp2*cas2%p2+s[i][k],tmp2%=p2;
			len[1]++,h1[1].push_back(tmp1);h2[1].push_back(tmp2);
		}
		for(re k=j+1;k<len[i];k++) cout<<s[i][k];
	}
}