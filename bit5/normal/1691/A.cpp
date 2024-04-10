#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,cnt[2];
inline void work(){
	n=read();
	cnt[0]=cnt[1]=0;
	while(n--)cnt[read()&1]++;
	printf("%d\n",min(cnt[0],cnt[1]));
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}