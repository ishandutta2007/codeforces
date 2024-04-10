#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 400005;
int n, ans, a[N], aa[N], b[N], bb[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=0; i<25; ++i){
		int sa=0, sb=0, x=(1<<i)-1;
		for(int j=1; j<=n; ++j)
			if(a[j]>>i&1) b[++sb]=a[j], bb[sb]=a[j]&x;
			else a[++sa]=a[j], aa[sa]=a[j]&x;
		ll cnt=0;
		for(int i=1; i<=sa; ++i)
			cnt+=sa-(upper_bound(aa+1, aa+sa+1, x-aa[i])-aa)+1-(aa[i]*2>x);
		for(int i=1; i<=sb; ++i)
			cnt+=sb-(upper_bound(bb+1, bb+sb+1, x-bb[i])-bb)+1-(bb[i]*2>x);
		cnt/=2;
		for(int i=1; i<=sb; ++i) cnt+=upper_bound(aa+1, aa+sa+1, x-bb[i])-aa-1;
		ans+=(cnt&1)<<i;

		memcpy(a+sa+1, b+1, sb<<2);
	}
	printf("%d\n", ans);
	return 0;
}