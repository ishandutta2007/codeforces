#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int cnt[26];
char s[N],t[N],p[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		scanf("%s",t);
		scanf("%s",p);
		memset(cnt,0,sizeof(cnt));
		for(int i=0,len=strlen(p);i<len;++i)
			cnt[p[i]-'a']++;
		int len1=strlen(s),len2=strlen(t),poi=0;
		for(int i=0;i<len2;++i){
			if(s[poi]==t[i]) ++poi;
			else if(cnt[t[i]-'a']==0){
				puts("NO");
				goto out;
			}else --cnt[t[i]-'a'];
		}
		if(poi<len1) puts("NO");
		else puts("YES");
		out:;
	}
	return 0;
}