#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int q,n,book[30];
char s[100005],t[100005];
signed main(){
	cin>>q;
	while(q--){
		cin>>n;
		scanf("%s%s",s+1,t+1);
		int fg=1,ans=0;
		for (register int i=1;i<=n;i++)
			if (s[i]>t[i]){
				fg=0;
				break;
			}
		if (fg==0){
			puts("-1");
			continue;
		}
		for (register char c='a';c<='z';c++){
			char d='z';
			for (register int i=1;i<=n;i++){
				if (s[i]!=c||s[i]==t[i])continue;
				d=min(d,t[i]);
			}
			if (d=='z')continue;
			ans++;
			for (register int i=1;i<=n;i++){
				if (s[i]!=c||s[i]==t[i])continue;
				s[i]=d;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}