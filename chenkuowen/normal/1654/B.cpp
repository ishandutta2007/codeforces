#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
int cnt[30];
char s[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i)
			cnt[s[i]-'a']++;
		for(int i=1;i<=n;++i){
			if(cnt[s[i]-'a']>1){
				--cnt[s[i]-'a'];
			}else{
				printf("%s\n",s+i);
				break;
			}
		}
	}
	return 0;
}