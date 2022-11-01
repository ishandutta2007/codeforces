#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
int n,cnt[26];char s[55],s2[55];vector<int>ans;
int main(){
	scanf("%d",&n);scanf("%s",s+1);scanf("%s",s2+1);
	for(int i=1;i<=n;i++)cnt[s[i]-'a']++;
	for(int i=1;i<=n;i++)cnt[s2[i]-'a']--;
	for(int i=0;i<26;i++)if(cnt[i]){puts("-1");return 0;}
	for(int i=1,pos;i<=n;i++)if(s[i]!=s2[i]){
		for(int j=i;j<=n;j++)if(s[j]==s2[i]){pos=j;break;}
		for(int j=pos-1;j>=i;j--)ans.pb(j),swap(s[j],s[j+1]);
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans)printf("%d ",x);puts("");
	return 0;
}