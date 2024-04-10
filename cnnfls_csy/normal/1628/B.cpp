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
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
/*inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}*/
int t,n,m,i,j;
set<pair<char,char> > s0,s1;
set<string> s2;
string st[100005];
void solve()
{
	s0.clear();s1.clear();s2.clear();
	cin>>n;fz1(i,n)cin>>st[i];
	fz1(i,n){
		if(st[i][0]==st[i].back()){
			puts("YES");return;
		}
	}
	fz1(i,n){
		if(s0.count(make_pair(st[i][st[i].size()-1],st[i][st[i].size()-2]))){
			puts("YES");return;
		}
		if(st[i].size()==2&&s1.count(make_pair(st[i][st[i].size()-1],st[i][st[i].size()-2]))){
			puts("YES");return;
		}
		string tmp=st[i];
		reverse(tmp.begin(),tmp.end());
		if(s2.count(tmp)){
			puts("YES");return;
		}
		if(st[i].size()==2){
			s0.insert(make_pair(st[i][0],st[i][1]));
		}
		else{
			s1.insert(make_pair(st[i][0],st[i][1]));
		}
		s2.insert(st[i]);
	}
	puts("NO");
}
int main()
{
	cin>>t;while(t--)solve();
	return 0;
}