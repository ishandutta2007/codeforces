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
int n;char m[1005][66];
int main(){
	int n=gi;bool flag=0;
	for(int i=1;i<=n;i++)scanf("%s",m[i]+1);
	for(int i=1;i<=n;i++){
		if(m[i][1]=='O'&&m[i][2]=='O'){flag=1;m[i][1]=m[i][2]='+';break;}
		if(m[i][4]=='O'&&m[i][5]=='O'){flag=1;m[i][4]=m[i][5]='+';break;}
	}
	if(flag){
		puts("YES");	
		for(int i=1;i<=n;i++)puts(m[i]+1);	
	}
	else puts("NO");
}