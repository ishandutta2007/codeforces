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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,a,b,c;
string st;
long long solve(int op)
{
	vector<int> v;
	int rema=0,remc=0,rb=0,rc=0;
	long long cur=0,ans=0;
	i=0;while(i<st.size()&&st[i]=='0'){if(i)rema++;else remc++;i++;}
	j=st.size()-1;while(i<j&&st[j]=='0'){if(j<st.size()-1)rema++;else remc++;j--;}
	while(i<=j){
		int k=i;while(k<=j&&st[i]==st[k])k++;
		if(st[i]=='0') v.push_back(k-i-1); else rb+=k-i-1;
		i=k;
	}
	sort(v.begin(),v.end());reverse(v.begin(),v.end());
	while(!v.empty()&&v.back()==0) v.pop_back(),rc++;
	if(op==1){
		if(!rb) return 0;
		cur=ans=b;rb--;
	}
	for(;;){
		while(!v.empty()&&v.back()==0) v.pop_back(),rc++;
		if(!v.empty()||rema) ans=max(ans,cur+a);
		if((!v.empty()||rema)&&rb){
			cur+=a;
			if(!v.empty())v.back()--; else rema--;
		}
		else if(rc) cur-=c,rc--,rb++;
		else if(remc) cur-=c,remc--;
		else break;
		ans=max(ans,cur);
		if(!rb) break;
		rb--;cur+=b;ans=max(ans,cur); 
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n>>a>>b>>c>>st;
		printf("%lld\n",max(solve(0),solve(1)));
	}
	return 0;
}