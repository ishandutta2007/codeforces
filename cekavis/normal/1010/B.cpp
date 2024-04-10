#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<iostream>

using namespace std;
#define ll long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define travel(i,x) for(int i=h[x];i;i=pre[i])
int n, m, cnt, op[30];
int main() {
	cin>>m>>n;
	rep(i, 0, n-1) cout<<1<<endl, fflush(stdout), cin>>op[i];
	if(op[0]==0) return puts("0"), 0;
	int l=0, r=m;
	while(l<=r){
		int mid=l+r>>1, tmp;
		cout<<mid<<endl, fflush(stdout), cin>>tmp;
		if(!tmp) return printf("%d", mid), 0;
		tmp*=op[cnt++%n];
		if(tmp==1) l=mid+1; else r=mid-1;
	}
	return 0;
}