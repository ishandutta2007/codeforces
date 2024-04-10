#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<complex>
#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;
#define inf 1001001001
#define infll 1001001001001001001LL
#define ll long long
#define dbg(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define gmax(a,b) (a)=max((a),(b))
#define gmin(a,b) (a)=min((a),(b))
#define Ri register int
#define gc getchar()
#define il inline
il int read(){
	bool f=true;Ri x=0;char ch;while(!isdigit(ch=gc))if(ch=='-')f=false;while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=gc;}return f?x:-x;
}
#define gi read()
#define FO(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
int a[1000000];
int main(){
	int t=gi;
	while(t--){
		ll x;char c;
		scanf("%c %I64d\n",&c,&x);
		ll y=0;
		for(int i=1;i<=18;i++,x/=10)y=y*2+(x&1);
		if(c=='+')a[y]++;
		if(c=='-')a[y]--;
		if(c=='?')printf("%d\n",a[y]);
	}
}