#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define inf 1000000000000
using namespace std;
int q,n;
char s[100005],t[100005];
int c[26][100005],l[26],num[26][100005],cnt[26];
int check(int pos){
	if (pos==-1)return inf;
	int ans=0;
	for (int i=0;i<26;i++)
		if (num[i][pos-1]>cnt[i])ans+=num[i][pos-1]-cnt[i];
	return ans;
}
signed main(){
	cin>>q;
	while(q--){
		cin>>n;
		scanf("%s",s+1);
		scanf("%s",t+1);
		for (int i=0;i<=n+1;i++)
			for (int j=0;j<26;j++)c[j][i]=-1,num[j][i]=0;
		memset(l,0,sizeof(l));
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++){
			for (int j=0;j<26;j++)num[j][i]=num[j][i-1];
			num[s[i]-'a'][i]++;
			c[s[i]-'a'][++l[s[i]-'a']]=i;
		}
		int ans=inf;
		int now=0;
		for (int i=1;i<=n;i++){
			for (int j=0;j<t[i]-'a';j++)ans=min(ans,now+check(c[j][cnt[j]+1]));
			now+=check(c[t[i]-'a'][cnt[t[i]-'a']+1]);
			cnt[t[i]-'a']++;
			if (now>inf)break;
		}
		if (ans!=inf)cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}