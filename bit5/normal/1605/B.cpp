#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1007;
int n,tot,cnt[N];
char s[N];
inline void work(){
	n=read(),scanf("%s",s+1);
	vector<int>ans;int s0=0;
	for(int i=1;i<=n;i++)if(s[i]=='0')s0++;
	for(int i=1;i<=n;i++)
		if((s[i]=='0')^(i<=s0))ans.push_back(i);
	if(ans.empty())puts("0");
	else{
		puts("1");
		printf("%lu ",ans.size());
		for(int x:ans)printf("%d ",x);
		puts("");
	}
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}