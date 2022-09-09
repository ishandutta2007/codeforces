#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int t,n,m,i,a[100005],s[200005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		rep(i,n){
			scanf("%d",&a[i]);
			a[i]=(a[i]==m?0:(a[i]<m?-1:1));
		}
		if(n==1&&a[1]==0){
			puts("yes");
			continue;
		}
		int lst=0,cur=0,s1=0,s2=0,mi=0x3f3f3f3f;
		rep(i,n) if(a[i]==0) s1=1;
		rep(i,n){
			int t=(a[i]>=0?1:-1),lst=cur;
			cur+=t;
			if(cur>mi) s2=1;
			mi=min(mi,lst);
		}
		if(s1*s2) puts("yes"); else puts("no");
	}
	return 0;
}