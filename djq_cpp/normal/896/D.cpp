#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
ll fa[100005],fb[100005],pw[100005],rev[100005];
ll exgcd(ll a,ll b,ll &x,ll &y) {
	if(!a&&!b)return -1;
	if(!b)return x=1,y=0,a;
	ll d=exgcd(b,a%b,y,x);
	return y-=a/b*x,d;
}
ll C(int n,int m,int t,int mp){
	int cc=fb[n]-fb[m]-fb[n-m];
	ll cur=fa[n]*(rev[m]*rev[n-m]%mp)%mp;
	return cc>=t?0:cur*pw[cc]%mp;
}
int solve(int n,int l,int r,int p,int t){
	fa[0]=1;
	fb[0]=0;
	int mp=1;
	rep(k,t)mp*=p;
	rep1(k,n){
		fa[k]=fa[k-1];
		fb[k]=fb[k-1];
		int c=k;
		while(c%p==0){
			c/=p;fb[k]++;
		}
		fa[k]=fa[k]*c%mp;
	}
	pw[0]=1;
	rep1(k,t)pw[k]=pw[k-1]*p;
	for(int k=0;k<=n;k++){
		ll tmp;exgcd(fa[k],mp,rev[k],tmp);rev[k]=(rev[k]%mp+mp)%mp;
	}
	ll ans=0LL;
	for(int s=0;s<=n;s++){
		ll cc=0LL;
		if(s-l>=0)cc+=C(s,(s-l)/2,t,mp);
		if(s-r-1>=0)cc-=C(s,(s-r-1)/2,t,mp);
		ans+=cc*C(n,s,t,mp);ans%=mp;
	}
	return (ans+mp)%mp;
}
int main(){
	int n,p,l,r;
	vector<pii> ans;
	scanf("%d%d%d%d",&n,&p,&l,&r);
	int tp=p,cp=2;
	while(cp*cp<=p){
		int ct=0,cur=1;
		while(p%cp==0){
			ct++;cur*=cp;p/=cp;
		}
		if(ct)ans.push_back(MP(cur,solve(n,l,r,cp,ct)));
		cp++;
	}
	if(p>1)ans.push_back(MP(p,solve(n,l,r,p,1)));
	ll res=0LL;
	rep(k,ans.size()){
		ll c1,c2;
		exgcd(ans[k].first,tp/ans[k].first,c1,c2);
		res=(res+c2*(tp/ans[k].first)%tp*ans[k].second)%tp;
	}
	printf("%I64d\n",(res+tp)%tp);
	return 0;
}