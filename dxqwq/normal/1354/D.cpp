#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int n=read(),m=read();
struct BIT {
	int bit[1000005];
	inline void add(int x,int y) {
		for(int i=x; i<=n; i+=(i&(-i)))	bit[i]+=y;
	}
	inline int query(int x) {
		int sum=0;
		for(int i=x; i; i-=(i&(-i)))	sum+=bit[i];
		return sum;
	}
} t;
signed main() {
	for(int i=1; i<=n; i++) {
		int x=read();
		t.add(x,1);
	}
	for(int i=1; i<=m; i++) {
		int x=read();
		if(x>0) t.add(x,1);
		else {
			x=-x;
			int l=1,r=n,k=0;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(t.query(mid)>=x)	k=mid,r=mid-1;
				else l=mid+1;
			}
			t.add(k,-1);
		}
	}
	for(int i=1; i<=n; i++) if(t.query(i)-t.query(i-1)) return 0&printf("%d\n",i);
	puts("0");
	return 0;
}