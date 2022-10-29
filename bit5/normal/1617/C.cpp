#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,a[N],cnt[N];
bool vis[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)cnt[i]=0,vis[i]=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<=n)cnt[a[i]]++,vis[a[i]]=1;
	}
	sort(a+1,a+n+1);int now=n,ans=0;
	for(int i=n;i && now;i--){
		while(vis[now])now--;
		if(!now)break;
		if(a[i]>n){
			if((a[i]-1)/2<now){puts("-1");return;}
			now--,ans++;
		}else if(cnt[a[i]]>1){
			cnt[a[i]]--;
			if((a[i]-1)/2<now){puts("-1");return;}
			now--,ans++;	
		}
	}
	printf("%d\n",ans);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}