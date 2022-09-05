#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;i++)
#define per(i,a,b) for(register int i=a;i>=b;i--)
const int N = 2097155;
typedef unsigned long long ll;
char s[N],t[N];
int n,cnt[N],all;ll a[N],b[N];
int main(){
	scanf("%d%s%s",&n,s,t);all=(1<<n);
	rep(i,1,all-1)cnt[i]=cnt[i>>1]+(i&1);
	rep(i,0,all-1)a[i]=(1LL*s[i]-'0')<<(cnt[i]*2),b[i]=(1LL*t[i]-'0')<<(cnt[i]*2);
	rep(j,0,n-1)rep(i,0,all-1)a[i]+=((i>>j)&1)?a[i^(1<<j)]:0,b[i]+=((i>>j)&1)?b[i^(1<<j)]:0;
	rep(i,0,all-1)a[i]*=b[i];
	rep(j,0,n-1)rep(i,0,all-1)a[i]-=((i>>j)&1)?a[i^(1<<j)]:0;
	rep(i,0,all-1)printf("%c",'0'+((a[i]>>(cnt[i]*2))&3));
	return 0;
}