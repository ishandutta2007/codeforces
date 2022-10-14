# include <bits/stdc++.h>
# define rr register
//kkkkkkkkkkk
const int N=200010,INF=0x3f3f3f3f;
int a[N];
int n;
int T;
bool pre[N],suf[N];
std::map <int,bool> Map;
inline int read(void){
	int res,f=1;
	char c;
	while((c=getchar())<'0'||c>'9')
		if(c=='-')f=-1;
	res=c-48;
	while((c=getchar())>='0'&&c<='9')
		res=res*10+c-48;
	return res*f;
}
int main(void){
	T=read();
	while(T--)
{
		Map.clear();
		n=read();
		for(rr int i=1;i<=n;++i){
			a[i]=read();
			pre[i]=suf[i]=false;
		}
		int cnt=0,maxx=0;
		for(rr int i=1;i<=n;++i){
			if(!Map[a[i]]) Map[a[i]]=true,++cnt;
			maxx=std::max(maxx,a[i]);
			if(cnt==i&&maxx==i){
				pre[i]=true;
			}
		}
		Map.clear();
		maxx=0,cnt=0;
		for(rr int i=n;i;--i){
			if(!Map[a[i]]){
				Map[a[i]]=true;
				++cnt;
			}
			maxx=std::max(maxx,a[i]);
			if(cnt==n-i+1&&maxx==n-i+1) suf[i]=true;}
		int ans=0;
		for(rr int i=1;i<n;++i) if(pre[i]&&suf[i+1]) ++ans;
		printf("%d\n",ans);
		for(rr int i=1;i<n;++i) if(pre[i]&&suf[i+1]) printf("%d %d\n",i,n-i);
	}

	return 0;
}