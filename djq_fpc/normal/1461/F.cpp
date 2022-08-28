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
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
string st;
int n,m,i,j,a[100005];
char ans[100005];
long long dp[1005];
int pre[1005];
void solve(vector<int> v,vector<int> pos,int ed)
{
	if(v.empty())return;
	if(v.back()<0){
		int i;fz(i,pos.back()-1,ed) ans[i]='+';
		ed=pos.back()-1;v.pop_back();pos.pop_back(); 
	}
	if(v.empty())return;
	long long s=1;int i,j;
	fz0k(i,v.size()){
		if(v[i]>0)s*=v[i];if(s>0xf3f3f3f3f3f3f3fll) return; 
		dp[i]=s;pre[i]=0;
	}
	fz0k(i,v.size()){
		if(v[i]<0){
			if(dp[i-1]-v[i]>dp[i]){
				dp[i]=dp[i-1]-v[i];
				pre[i]=i;
			}
		}
		long long s=1;
		for(j=i;j;j--){
			if(v[j]>=0) s*=v[j];
			if(dp[j-1]+s>dp[i]){
				dp[i]=dp[j-1]+s;
				pre[i]=j;
			}
		}
	}
	int t=v.size()-1;pos.push_back(ed+1);
	while(t!=-1){
		int tt=pre[t]-1;
		if(v[t]<0){
			for(j=pos[t]-1;j<pos[t+1];j++){
				ans[j]='+';
			}
		}
		t=tt;
	}
}
int main()
{
	scanf("%d",&n);fz1(i,n)scanf("%d",&a[i]);rdst(st,15);
	if(st.size()==1){
		fz1(i,n-1) ans[i]=st[0];
	}
	else if(st.find('+')==string::npos){
		fz1(i,n-1) ans[i]='*';
		fz1(i,n) if(a[i]==0) break;
		ans[i-1]='-';
	}
	else if(st.find('*')==string::npos){
		fz1(i,n-1) ans[i]='+';
	}
	else{
		fz1(i,n-1) ans[i]='*';
		vector<int> v,pos;
		fz1(i,n){
			if(a[i]==0){
				ans[i]=ans[i-1]='+';
				solve(v,pos,i-1);
				v.clear();pos.clear();
			}
			else if(a[i]==1){
				if(v.empty()){
					ans[i-1]=ans[i]='+';
				}
				else if(v.back()<0){
					v.back()--;
				}
				else{
					v.push_back(-1);
					pos.push_back(i); 
				}
			}
			else{
				v.push_back(a[i]);
				pos.push_back(i);
			}
		}
		solve(v,pos,n);
	}
	fz1(i,n-1){
		printf("%d%c",a[i],ans[i]);
	}
	printf("%d\n",a[n]);
	return 0;
}