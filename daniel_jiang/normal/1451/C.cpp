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

const int N=1e6+5;
int T,n,k,ans,cnt[30],cnt1[30];
char s[N],s1[N];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
	while(T--){
		rd(n);rd(k);ans=0;
		scanf("%s %s",s+1,s1+1);
		for(re i=0;i<30;i++) cnt[i]=cnt1[i]=0;
		for(re i=1;i<=n;i++) cnt[s[i]-'a']++,cnt1[s1[i]-'a']++;
		for(re i=0;i<26;i++){
			if(i>0) cnt[i]+=cnt[i-1]/k*k;
			if(cnt[i]<cnt1[i]) ans=1;
			else cnt[i]-=cnt1[i];
		}
		if(!ans) puts("Yes");
		else puts("No");
	}
	return 0;
}

// ---------- Main ---------- //