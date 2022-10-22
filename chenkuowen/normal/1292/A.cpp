#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e5;
int a[2][MAX_N],cnt=0;
int check(int x,int y){
	if(!a[x][y]) return 0;
	int ret=0;
	if(a[x^1][y]) ++ret;
	if(a[x^1][y-1]) ++ret;
	if(a[x^1][y+1]) ++ret;
	return ret;
}
int main(){
	int n,q; scanf("%d%d",&n,&q);
	for(int i=1;i<=q;++i){
		int r,c; scanf("%d%d",&r,&c);
		--r;
		cnt-=check(r,c);
		a[r][c]^=1;
		cnt+=check(r,c);
		if(cnt>0) puts("No");
		else puts("Yes");
	}
	return 0;
}