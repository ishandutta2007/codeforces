#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int tt,n,m,i,j,ans,len[2100005];
string s,t,pre,suf;
void manacher(const string &st)
{
	int i,l=0,r=0;
	for (i=0;i<st.length();i++)
	{
		if (r>i) len[i]=min(len[2*l-i],r-i); else len[i]=1;
		while (st[i+len[i]]==st[i-len[i]]) len[i]++;
		if (i+len[i]>r)
		{
			l=i;
			r=i+len[i];
		}
	}
}
string solve()
{
	t.clear();t.push_back('!');t.push_back('#');
	int i,ans=0,pos=0;
	fz0k(i,s.size()){
		t.push_back(s[i]);
		t.push_back('#');
	}
	manacher(t);
	fz0k(i,t.size()){
		if(i-len[i]==0){
			if(len[i]-1>ans){
				ans=len[i]-1;
				pos=1;
			}
		}
		if(i+len[i]==t.size()){
			if(len[i]-1>ans){
				ans=len[i]-1;
				pos=-1;
			}
		}
	}
	string res;res.clear();
	if(pos==1){
		fz0k(i,ans) res.push_back(s[i]);
	}
	if(pos==-1){
		fz0k(i,ans) res.push_back(s[s.size()-ans+i]);
	}
	return res;
}
int main()
{
	read(tt);
	while(tt--)
	{
		rdst(s,1000005);
		pre.clear();suf.clear();
		n=s.length();ans=0;
		while(ans<=n-ans-1&&s[ans]==s[n-ans-1]){
			pre.push_back(s[ans++]);
		}
		if(ans*2>=n){
			puts(s.c_str());
			continue;
		}
		suf=pre;reverse(suf.begin(),suf.end());
		s=s.substr(ans,n-ans-ans);
		puts((pre+solve()+suf).c_str());
	}
	return 0;
}