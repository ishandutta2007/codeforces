// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back

using namespace std;
typedef long long ll;

template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}

// ---------- IO ---------- //

int T,n,q,a,b,c,d,l,r;
char s[105];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
	while(T--){
		rd(n);rd(q);a=b=n+1;c=d=0;
		scanf("%s",s+1);
		for(re i=1;i<=n;i++)
			if(s[i]=='0') a=min(a,i),c=max(c,i);
			else b=min(b,i),d=max(d,i);
		for(re i=1;i<=q;i++){
			rd(l);rd(r);
			if(s[l]=='0'&&a<l) puts("YES");
			else if(s[l]=='1'&&b<l) puts("YES");
			else if(s[r]=='0'&&c>r) puts("YES");
			else if(s[r]=='1'&&d>r) puts("YES");
			else  puts("NO");
		}
	}
	return 0;
}

// ---------- Main ---------- //