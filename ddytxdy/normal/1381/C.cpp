#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int N=1e5+50;
int T,n,x,y,a[N],cnt[N],cnt2[N],b[N],qq[N],t,mx,pos[N],m,dat;
priority_queue<pii>q;
void solve(){
	scanf("%d%d%d",&n,&x,&y);while(q.size())q.pop();
	for(int i=1;i<=n+1;i++)cnt[i]=cnt2[i]=b[i]=0;mx=t=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1;i<=n+1;i++)
		if(cnt[i])q.push(mp(cnt[i],i));
		else dat=i;
	for(int i=1;i<=x;i++){
		int x=q.top().second;q.pop();
		cnt2[x]++;cnt[x]--;
		if(cnt[x])q.push(mp(cnt[x],x));
	}
	for(int i=1;i<=n;i++)if(cnt2[a[i]])b[i]=a[i],cnt2[a[i]]--;
	for(int i=1;i<=n+1;i++)mx=max(mx,cnt[i]);m=n-x;
	if(mx*2-m-(n-y)>0){puts("NO");return;}
	for(int i=1;i<=n+1;i++){
		pos[i]=t;
		while(cnt[i]--)qq[t++]=i;
	}
	for(int i=1;i<=n;i++)if(!b[i]){
		b[i]=qq[(pos[a[i]]+m/2)%m];pos[a[i]]++;
		if(b[i]==a[i])b[i]=dat,y++;
	}
	for(int i=1;i<=n;i++)if(b[i]!=a[i]&&b[i]!=dat&&y!=n)b[i]=dat,y++;
	puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}