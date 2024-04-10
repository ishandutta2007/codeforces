#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2000005;
int T, r[N], f[N], ans, ans2, ans3, mx, pos, n;
char s[N], t[N];
void work(){
	int ss=0;
	for(int i=0; i<n && s[i]==s[n-i-1]; ++i) ++ss;
	ss=min(ss, n/2);

	mx=pos=0;
	for(int i=n<<1; i; i-=2) s[i+1]='#', s[i]=s[(i-1)>>1];
	s[n*2+2]=0;
	s[1]='#';
	s[0]=-1;
	memset(r, 0, (n*2+3)<<2);
	for(int i=1; s[i]; ++i){
		int &tmp=r[i];
		if(i<=mx) tmp=min(r[(pos<<1)-i], mx-i+1);
		while(s[i-tmp]==s[i+tmp]) ++tmp;
		if(mx<i+tmp-1) mx=i+tmp-1, pos=i;
		// printf("[%d]", r[i]);
	}
	// puts("");
	memset(f, 0, (n+1)<<2);
	for(int i=1; i<=n+1; ++i)
		f[(i-r[i]+1+1)/2]=max(f[(i-r[i]+1+1)/2], i);
	for(int i=1; i<=(n+1)/2; ++i) f[i]=max(f[i], f[i-1]);
	// for(int i=1; i<=n; ++i) printf("[%d]", i*2-f[i]+1);
	// puts("");
	for(int i=1; i<=(n+1)/2 && i<=ss+1; ++i){
		int x=f[i]-i*2+1;
		if((i-1)*2+x>ans) ans=(i-1)*2+x, ans2=i+x-1, ans3=i-1;
	}
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%s", s), n=strlen(s);
		ans=0, memcpy(t, s, n);
		work();
		swap(ans2, ans3);
		memcpy(s, t, n);
		reverse(s, s+n);
		work();
		// printf("%d\n", ans);
		for(int i=0; i<ans3; ++i) putchar(t[i]);
		for(int i=n-ans2; i<n; ++i) putchar(t[i]);
		puts("");
	}
	return 0;
}