#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,E=524288,N=300005;
int t,n,a[N],q,ans,pos;
char c[N],d;
int jd(int x){
	if(x<=0)
		return 0;
	if(c[x]=='a'&&c[x+1]=='b'&&c[x+2]=='c')
		return 1;
	return 0;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&q);
	scanf("%s",c+1);
	for(int i=1;i<=n-2;++i)
		ans+=jd(i);
	while(q--){
		scanf("%d %c\n",&pos,&d);
		ans-=jd(pos-2)+jd(pos-1)+jd(pos);
		c[pos]=d;
		ans+=jd(pos-2)+jd(pos-1)+jd(pos);
		printf("%d\n",ans);
	}
}