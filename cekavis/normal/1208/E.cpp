#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005;
int n, w, m, q[N], a[N];
ll ans, f[N];
int main() {
	scanf("%d%d", &n, &w);
	for(int i=1; i<=n; ++i){
		scanf("%d", &m);
		for(int j=1; j<=m; ++j) scanf("%d", a+j);
		if(m*2<=w){
			int now=0;
			for(int j=1; j<=m; ++j){
				now=max(now, a[j]);
				f[j]+=now, f[j+1]-=now;
			}
			f[m+1]+=now, f[w-m+1]-=now;
			now=0;
			for(int j=1; j<=m; ++j){
				now=max(now, a[m-j+1]);
				f[w-j+1]+=now, f[w-j+2]-=now;
			}
		}
		else{
			int r=0, l=1;
			for(int j=1; j<=w; ++j){
				while(r>=l && j-q[l]>w-m) ++l;
				if(j<=m){
					while(r>=l && a[q[r]]<a[j]) --r;
					q[++r]=j;
				}
				if(a[q[l]]>0 || (w-m<j && j<=m)) f[j]+=a[q[l]], f[j+1]-=a[q[l]];
				// if(j==w) printf(">> %d %d\n", q[l], m);
			}
		}
	}
	for(int i=1; i<=w; ++i) printf("%lld%c", ans+=f[i], " \n"[i==w]);
	return 0;
}