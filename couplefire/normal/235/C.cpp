#include <cstdio>
#include <cstring>
#include <algorithm>
#define last last2 
 
using namespace std;
 
typedef long long ll;
 
int ch[2000005][26],fa[2000005],mx[2000005],size[2000005];
int last=1,root=1,tot=1;
 
void add(char x) {
  x-='a';
  int p=last,np=++tot;
  mx[np]=mx[p]+1;
  for(;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
  if (!p) fa[np]=root;
  else {
  	int q=ch[p][x];
  	if (mx[q]==mx[p]+1) fa[np]=q;
  	else {
  		int nq=++tot;
  		memcpy(ch[nq],ch[q],sizeof(ch[nq]));
  		mx[nq]=mx[p]+1;
  		fa[nq]=fa[q];
  		fa[q]=fa[np]=nq;
  		for(;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
	  }
  }
  size[np]++;
  last=np;
}
 
int sum[2000005],id[2000005];
 
void dp(int n) {
  for(int i=1;i<=tot;i++) sum[mx[i]]++;
  for(int i=2;i<=n;i++) sum[i]+=sum[i-1];
  for(int i=1;i<=tot;i++) id[sum[mx[i]]--]=i;
  for(int i=tot;i>1;i--) size[fa[id[i]]]+=size[id[i]];
}
 
char s[2000005];
int vis[2000005];
 
ll match(int id,int n) {
  int now=1,x,len=0;
  ll ans=0;
  for(int i=0;i<2*n;i++) {
  	x=s[i]-'a';
  	for(;now&&!ch[now][x];now=fa[now]) len=mx[fa[now]];
  	if (!now) {
  		now=root;
  		len=0;
	  }
	else {
		now=ch[now][x];
		len++;
	}
	if (len>=n) {
		for(;mx[fa[now]]>=n;now=fa[now]) len=mx[fa[now]];
		if (vis[now]!=id) {
			ans+=size[now];
			vis[now]=id;
		}
	}
  }
  return ans;
}
 
int main() {
  scanf("%s",s);
  int len=strlen(s);
  for(int i=0;i<len;i++) add(s[i]);
  dp(len);
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {
  	scanf("%s",s);
  	len=strlen(s);
  	for(int j=len;j<2*len;j++) s[j]=s[j-len];
  	printf("%lld\n",match(i,len));
  }
  return 0;
}