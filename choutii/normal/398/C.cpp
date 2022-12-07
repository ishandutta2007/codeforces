#include<bits/stdc++.h>
#define FO(x) {freopen(#x".in","r",stdin);\
				freopen(#x".out","w",stdout);}
#define fir first
#define sec second
using namespace std;
typedef long long ll;
template<typename T>inline bool cmin(T &a,const T &b){ return a>b?a=b,1:0;}
template<typename T>inline bool cmax(T &a,const T &b){ return a<b?a=b,1:0;}
int main(){
	int n,i;
	scanf("%d",&n);
	if(n==5){
		puts("1 2 3");
		puts("1 3 3");
		puts("2 4 2");
		puts("4 5 1");
		puts("3 4");
		puts("3 5");
	}else{
		for(i=1;i<=n/2;i++)printf("%d %d %d\n",i,i+(n/2),1);
		for(i=n/2+1;i<n;i++)printf("%d %d %d\n",i,i+1,2*(i-n/2)-1);
		for(i=1;i<n/2;i++)printf("%d %d\n",i,i+1); 
		puts("1 3");
	}
	return 0;
}