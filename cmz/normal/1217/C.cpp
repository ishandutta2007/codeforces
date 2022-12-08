#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
char s[maxn];
int n,m;
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%s",s+1);
		n=strlen(s+1);
		int len=0,ans=0,sum=0;
		for (int i=1;i<=n;++i) {
			if (s[i]=='0') {
				++len;
				continue;
			}
			int sum=0;
			for (int j=i;j<=n;++j) {
				++len;
				sum<<=1;
				sum|=(s[j]=='1');
				ans+=(sum<=len);
				if (sum>len) break;
			}
			len=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}