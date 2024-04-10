#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("inline-functions-called-once")
#include<bits/stdc++.h>
using namespace std;
const int N=100000+10;
int n,q;char s[N],now[N];
bitset<N>m[27],ans;
signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)
		m[s[i]-'a'][i]=1;
	scanf("%d",&q);
	while(q--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int x;char v;
			scanf("%d %c",&x,&v);
			m[s[x]-'a'][x]=0;
			m[(s[x]=v)-'a'][x]=1;
		}else{
			int x,y;scanf("%d%d %s",&x,&y,now+1);
			ans.set();
			int len=strlen(now+1);
			for(int i=1;i<=len;i++)
				ans&=m[now[i]-'a']>>(i-1);
			int L=(ans>>x).count();
			int R=(ans>>y-len+2).count();
			printf("%d\n",(L<R)?0:L-R);
		}
	}
	return 0;
	//cout<<""
}