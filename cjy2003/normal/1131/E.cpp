#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,len[100010],ans;
bool hv[100010][26];
char s[100010],*t[100010];
int find(int p,int c)
{
	int res=0,cur=0;
	for(int i=1;i<=len[p];++i)
		if(t[p][i]==c)++cur,res=max(res,cur);
		else cur=0;
	if(p==1)return res;
	int pre=0,suf=0;
	for(int i=1;i<=len[p];++i)
		if(t[p][i]==c)++pre;
		else break;
	for(int i=len[p];i;--i)
		if(t[p][i]==c)++suf;
		else break;
	if(pre==len[p])return find(p-1,c)*(1+len[p])+len[p];
	return max(hv[p-1][c]?pre+suf+1:max(pre,suf),res);
}
int main()
{
	scanf("%d",&n);
	int tot=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+tot+1);
		t[i]=s+tot;
		len[i]=strlen(s+tot+1);
		tot+=len[i];
	}
	for(int i=1;i<=tot;++i)s[i]-='a';
	for(int i=1;i<=n;++i)
	{
		memcpy(hv[i],hv[i-1],sizeof(hv[i]));
		for(int j=1;j<=len[i];++j)hv[i][t[i][j]]=1;
	}
	for(int i=0;i<26;++i)ans=max(ans,find(n,i));
	printf("%d",ans);
	return 0;
}