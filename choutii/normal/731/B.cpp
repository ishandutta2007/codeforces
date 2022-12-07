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
#define ig read()
#define FO(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
int n,a[233333];
int main(){
	n=ig;
	int sum=0,flag=0;
	for(int i=1;i<=n;i++)a[i]=gi;
	for(int i=1;i<=n;i++){
		if(!a[i]){
			if(sum%2==1){
				
				puts("NO");return 0;
			}
			sum=0;
		}
		else {
			sum+=a[i];
		} 
	}
	if(sum%2==0)puts("YES");
	else puts("NO");
}