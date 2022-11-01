#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005;
int n, mn, cntmn, ans, ansx, ansy, a[N];
char s[N];
void work(int f, int x, int y){
	if(f>ans) ans=f, ansx=x, ansy=y;
}
int main() {
	scanf("%d%s", &n, s+1);
	for(int i=1; i<=n; ++i){
		a[i]=a[i-1]+(s[i]=='('?1:-1);
		mn=min(mn, a[i]);
	}
	if(a[n]) return puts("0\n1 1"), 0;
	for(int i=1; i<=n; ++i) cntmn+=a[i]==mn;
	ans=cntmn, ansx=ansy=1;
	int cnt=-n, cnt2=-n, x=0, y=0;
	for(int i=1; i<=n; ++i){
		if(s[i]=='('){
			if(a[i-1]==mn) cnt=0, x=i, cnt2=-n, y=0;
			else if(a[i-1]==mn+1 || !y) cnt2=0, y=i;
		}
		else{
			work(cnt, x, i);
			work(cnt2+cntmn, y, i);
		}
		cnt+=(a[i]==mn+1);
		cnt2+=(a[i]==mn+2);
	}
	cnt=x=y=0;
	for(int i=1; i<=n && a[i]!=mn; ++i){
		cnt+=a[i]==mn+1;
		x=i;
	}
	for(int i=n; i && a[i]!=mn; --i){
		cnt+=a[i]==mn+1;
		y=i;
	}
	if(y) work(cnt, x+1, y);
	cnt=x=y=0;
	for(int i=1; i<=n && a[i]!=mn; ++i){
		cnt+=a[i]==mn+1;
		x=i;
	}
	for(int i=n; i && a[i]!=mn; --i){
		cnt+=a[i]==mn+1;
		y=i;
	}
	if(y) work(cnt, x+1, y);
	cnt=x=y=0;
	for(int i=1; i<=n && a[i]!=mn+1; ++i){
		cnt+=a[i]==mn+2;
		x=i;
	}
	for(int i=n; i && a[i]!=mn+1; --i){
		cnt+=a[i]==mn+2;
		y=i;
	}
	if(y) work(cnt+cntmn, x+1, y);
	printf("%d\n%d %d\n", ans, ansx, ansy);
	return 0;
}