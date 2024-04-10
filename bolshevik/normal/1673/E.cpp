#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e6;
int n,k,b[o],p,g[o];long long s;bool ans[o];
inline bool calc(int x,int y){
	if(!x&&y<=0) return true;
	--x;--y;y=max(y,0);
	if(x<0) return false;
	if(!x) return !y;
	bool res=((x&y)==y);
	if(!(y&g[x])) y^=(y&(2*g[x]-1)),res^=((x&y)==y);
	return res;
}
int main(){
	scanf("%d%d",&n,&k);++k;
	for(int i=0;i<n;++i) scanf("%d",&b[i]);
	for(int i=1;i<n;++i) if(i&1) g[i]=1;else g[i]=g[i>>1]<<1;
	for(int i=0,j;i<n;++i) for(j=i,s=b[i];j<n;++j){
		if(i^j) s*=(1ll<<min(b[j],20));
		if(s>=(1<<20)) break;
		if(!i){if(calc(n-j-1,k-1)) ans[s]^=1;}
		else if(j==n-1){if(calc(i,k-1)) ans[s]^=1;}
		else if(calc(i+n-j-2,k-2)) ans[s]^=1;
	}
	for(p=o-1;p&&!ans[p];--p);
	for(;p+1;) printf("%d",(int)ans[p--]);
	return 0;
}