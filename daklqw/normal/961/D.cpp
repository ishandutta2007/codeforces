#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 100010
#define LL long long
int n,xs[MAXN],ys[MAXN];

bool ina[MAXN];
inline LL cha(LL x1,LL y1,LL x2,LL y2){
	return x1*y2-x2*y1;
}
bool pd(int a,int b,int c){
	return cha(xs[b]-xs[a],ys[b]-ys[a],xs[c]-xs[b],ys[c]-ys[b])==0;
}
bool judge(int a,int b){
	for(int i=1;i<=n;++i)ina[i]=pd(a,b,i);
	int t1,t2;t1=t2=0;
	for(int i=1;i<=n;++i)
		if(!ina[i]){
			if(!t1)t1=i;
			else if(!t2)t2=i;
			else if(!pd(t1,t2,i))return false;
		}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&xs[i],&ys[i]);
	if(n<=3)puts("YES");
	else puts(judge(1,2)||judge(2,3)||judge(1,3)?"YES":"NO");
	return 0;
}