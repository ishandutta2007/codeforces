#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 3005;
ll ans;
int r, c, n, k, sum, nxt[N], cnt[N], f[N][N];
pair<int,int> a[N];
int main() {
	scanf("%d%d%d%d", &r, &c, &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
	sort(a+1, a+n+1);
	for(int j=1; j<=c; ++j){
		nxt[nxt[1]=j+1]=j+2, cnt[1]=sum=0;
		int now=1;
		for(int i=1; i<=r; ++i){
			while(now<=n && a[now].first==i){
				if(a[now].second<=j){
					int last=0, t=1, x=a[now].second;
					while(nxt[t]<=x+1){
						f[t][++cnt[t]]=i;
						if(cnt[t]>=k)
							sum+=(f[t][cnt[t]-k+1]-f[t][cnt[t]-k])*(nxt[t]-t);
						if(last && cnt[t]>=k && cnt[last]>=k && memcmp(f[t]+cnt[t]-k+1, f[last]+cnt[last]-k+1, k<<2)==0)
							nxt[last]=nxt[t];
						else last=t;
						t=nxt[t];
					}
					if(t<=x){
						nxt[x+1]=nxt[t], nxt[t]=x+1;
						cnt[x+1]=0;
						for(int y=max(1, cnt[t]-k+1); y<=cnt[t]; ++y)
							f[x+1][++cnt[x+1]]=f[t][y];
						f[t][++cnt[t]]=i;
						if(cnt[t]>=k)
							sum+=(f[t][cnt[t]-k+1]-f[t][cnt[t]-k])*(nxt[t]-t);
					}
				}
				++now;
			}
			ans+=sum;
		}
	}
	printf("%lld\n", ans);
	return 0;
}