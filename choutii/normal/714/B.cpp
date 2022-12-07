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
int cnt;
int n,a[123456];
map<int,int>m;
int main(){
	n=gi;
	for(int i=1;i<=n;i++){
		a[i]=gi;
		if(!m[a[i]])cnt++;
		++m[a[i]]; 
	}
	if(cnt==1)puts("YES");
	if(cnt==2)puts("YES");
	if(cnt>=4)puts("NO");
	if(cnt==3){
		int a[4],aa=0;
		for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
			a[++aa]=it->first;
		}
		sort(a+1,a+aa+1);
		if(2*a[2]==a[1]+a[3])puts("YES");
		else puts("NO");
	}
}