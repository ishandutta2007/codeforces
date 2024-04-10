#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e6+10,base=13331,base2=1145141,mod1=998244353,mod2=1e9+7;
int n,ans[MAXN];
char s[MAXN];
ll Hash[MAXN],Hash2[MAXN],power[MAXN],power2[MAXN];
ll H(int L,int R){
	return (Hash[R]-Hash[L-1]*power[R-L+1]%mod1+mod1)%mod1;
}
ll H2(int L,int R){
	return (Hash2[R]-Hash2[L-1]*power2[R-L+1]%mod2+mod2)%mod2; 
}
int main(){
	scanf("%d%s",&n,s+1);
	power[0]=power2[0]=1;rep(i,1,n)power[i]=power[i-1]*base%mod1,power2[i]=power2[i-1]*base2%mod2; 
	rep(i,1,n)Hash[i]=(Hash[i-1]*base%mod1+(s[i]-'a'+1))%mod1,Hash2[i]=(Hash2[i-1]*base2%mod2+(s[i]-'a'+1))%mod2;
	rep(i,1,n/2){
		//border
		int j=n-i+1;
		if(s[i]!=s[j])continue; 
		int L=1,R=i-1,ret=0;
		while(L<=R){
			int mid=(L+R)>>1;
			if(H(i-mid,i+mid)==H(j-mid,j+mid) &&
			H2(i-mid,i+mid)==H2(j-mid,j+mid)){
				ret=mid;
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		ans[i-ret]=max(ans[i-ret],ret*2+1);
	} 
	rep(i,2,n/2)ans[i]=max(ans[i],ans[i-1]-2);
	rep(i,1,(n+1)/2){
		if(ans[i]<=0)printf("-1 ");
		else printf("%d ",ans[i]);
	}

	return 0;
}