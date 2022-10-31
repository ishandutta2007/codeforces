#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100005
int T, n, k, cnt[26], cnt1[26];
char s[N], t[N];
inline int calc(int x) { return (k-x%k)%k; }
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%s", &n, &k, s+1);
		if(n%k) { puts("-1"); continue; }
		memset(cnt, 0, sizeof(cnt));
		memset(cnt1, 0, sizeof(cnt1));
		int ret=0, ret1=0, ok=1, idx=1, pr=0;
		while(idx<=n&&s[idx]=='z') ++cnt[25], ++cnt1[25], ++idx;
		if(idx==n+1) { puts(s+1); continue; }
		for(int j=s[idx]-'a'+1; j<26; ++j) if(ret1-calc(cnt1[j])+calc(cnt1[j]+1)<=n-idx) { t[idx]=j+'a'; break; }
		pr=idx-1;
		if(!t[idx]) ret1=0x3f3f3f3f, exit(114);
		++cnt[s[idx]-'a'];
		if(t[idx]) ++cnt1[t[idx]-'a'];
		for(int i=0; i<26; ++i) ret+=calc(cnt[i]), ret1+=calc(cnt1[i]);
		if(ret>n-idx) ok=0;
		for(int i=idx+1; i<=n; ++i)
		{
			int x=s[i]-'a';
			int fl=0;
			if(ok)
			{
				for(int j=x+1; j<26; ++j)
				if(ret-calc(cnt[j])+calc(cnt[j]+1)<=n-i)
				{
					t[i]='a'+j, ret1=ret-calc(cnt[j])+calc(cnt[j]+1);
					memcpy(cnt1, cnt, sizeof(cnt));
					++cnt1[j], pr=i-1, fl=1; break;
				}
			}
			if(ret-calc(cnt[x])+calc(cnt[x]+1)>n-i) ok=0;
			else ret=ret-calc(cnt[x])+calc(cnt[x]+1), ++cnt[x];
			if(!fl) for(int j=0; j<26; ++j)
			{
				if(ret1-calc(cnt1[j])+calc(cnt1[j]+1)<=n-i) { t[i]='a'+j, ret1-=calc(cnt1[j]), ++cnt1[j], ret1+=calc(cnt1[j]); break; }
			}
			if(!t[i]) ret1=0x3f3f3f3f;
		}
		if(ok) puts(s+1);
		else
		{
			if(ret1) { exit(114); continue; }
			for(int i=1; i<=pr; ++i) putchar(s[i]);
			for(int i=pr+1; i<=n; ++i) putchar(t[i]);
			puts("");
		}
		out:;
	}
	return 0;
}