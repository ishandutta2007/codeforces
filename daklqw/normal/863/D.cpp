#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <cstdlib>
using namespace std;
#define For(a,b,c) for(int a=b;a<=c;++a)
#define dFor(a,b,c) for(int a=b;a>=c;--a)
#define FP fastpow
#define EGD exgcd
#define P MOD
#define MAXN 200010
#define mp make_pair
#define pb push_back
#define OP operator
#define IT ::iterator
#define LLI long long
#define ULL unsigned long long
#define U unsigned
#define ED end()
#define BE begin()
#define PQ priority_queue
#define gc getchar
#define INF 0x3f3f3f3f
int MOD=1000000007;
typedef pair<int,int> PPI;
typedef vector<int> VI;
typedef queue<int> QI;
typedef map<string,int> MSI;
typedef set<int> SI;
char t;template<typename T>inline void r(T&x){x=0;
while(t=getchar(),!isdigit(t));
while(x=(x<<1)+(x<<3)+t-48,t=gc(),isdigit(t));}
template<typename T1,typename T2>inline void r(T1&a,T2&b){r(a);r(b);}
template<typename T>inline T fastpow(T a,T b){a%=P;T res=1;
for(;b;b>>=1,a=(1LL*a*a)%P)if(b&1)res=(1LL*a*res)%P;return res;}
template<typename T>T EGD(T a,T b,T&x,T&y){
if(b==0){x=1,y=0;return a;}T t=EGD(b,a%b,y,x);y-=a/b*x;return t;}
template<typename T>T inv(T a){T x,y;EGD(a,P,x,y);if(x<0)return x+P;else return x;}
template<typename T>T gcd(T a,T b){return b==0?a:gcd(b,a%b);}

int n,m,k,sums[MAXN],kind[MAXN],ls[MAXN],rs[MAXN],ans[MAXN];

struct CMP{inline bool OP()(const int&a,const int&b){return a<b;}};//
typedef priority_queue<int,vector<int>,CMP> PQC;
inline int scmp(int a,int b){}

int main(){
	r(n);r(m,k);
	For(i,1,n)r(sums[i]);
	For(i,1,m)r(kind[i]),r(ls[i],rs[i]);
	For(i,1,k)r(ans[i]);
	dFor(i,m,1)
		For(j,1,k)
			if(ls[i]<=ans[j]&&ans[j]<=rs[i]){
				if(kind[i]==1){
					--ans[j];
					if(ans[j]<ls[i])ans[j]=rs[i];
				}else{
					ans[j]=rs[i]-ans[j]+ls[i];
				}
			}
	For(i,1,k)cout<<sums[ans[i]]<<" ";cout<<endl;
	return 0;
}