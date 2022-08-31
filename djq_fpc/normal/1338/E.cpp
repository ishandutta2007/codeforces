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
int n,m,i,j,g[8005][8005],deg[8005];
long long ans;
queue<int> qx;
bool cmp(int x,int y)
{
	return g[x][y];
}
int main()
{
	scanf("%d",&n);
	fz1(i,n){
		getchar(); 
		fz1(j,n/4){
			char c=getchar();
			int t=(c<='9'?(c&15):(c-'A'+10));
			g[i][j*4-3]=!!(t&8);
			g[i][j*4-2]=!!(t&4);
			g[i][j*4-1]=!!(t&2);
			g[i][j*4]=!!(t&1);
		}
	}
	fz1(i,n){
		fz1(j,n)if(i!=j&&g[i][j]){
			deg[j]++;
		}
	}
	fz1(i,n){
		if(!deg[i]){
			qx.push(i);
			deg[i]=-1;
		}
	}
	int cnt=n;
	while(!qx.empty()){
		int x=qx.front();qx.pop();
		cnt--;ans+=1ll*cnt*(614ll*n+1);
		fz1(i,n)if(g[x][i]&&--deg[i]==0){
			deg[i]=-1;qx.push(i);
		}
	}
	if(cnt==0){
		cout<<ans<<endl;
		return 0;
	}
	int x=0;
	fz1(i,n) if(deg[i]>deg[x]) x=i;
	vector<int> s1,s2;
	fz1(i,n) if(deg[i]!=-1){
		if(i==x||g[i][x]){
			s1.push_back(i);
		}
		else{
			s2.push_back(i);
		}
	}
	sort(s1.begin(),s1.end(),cmp);
	sort(s2.begin(),s2.end(),cmp);
//	cerr<<s1.size()<<endl;
//	cerr<<s2.size()<<endl;
	ans+=3ll*s1.size()*s2.size();
	fz0k(i,s1.size()) deg[s1[i]]-=i;
	fz0k(i,s2.size()) deg[s2[i]]-=i;
	fz0k(i,s1.size()) fz0k(j,i){
		ans+=(deg[s1[i]]==deg[s1[j]])?4:3;
	}
	fz0k(i,s2.size()) fz0k(j,i){
		ans+=(deg[s2[i]]==deg[s2[j]])?4:3;
	}
	cout<<ans<<endl;
	return 0;
}