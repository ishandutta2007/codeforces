#include <iostream>
#include <cstdio>
#include <cstring>
#define mod1 1000000007 
#define mod2 19260817
#define int long long
using namespace std;
int n,len[100005],tot,p1[1000005],p2[1000005],hash1[1000005],hash2[1000005];
char s[1000005],ans[1000005];
inline int value(char c){
	if (c>='a'&&c<='z')return c-'a'+1;
	if (c>='A'&&c<='Z')return c-'A'+27;
	if (c>='0'&&c<='9')return c-'0'+53;
}
inline int gethash1(int l,int r){
	return ((hash1[r]-hash1[l-1]*p1[r-l+1])%mod1+mod1)%mod1;
}
inline int gethash2(int l,int r){
	return ((hash2[r]-hash2[l-1]*p2[r-l+1])%mod2+mod2)%mod2;
}
signed main(){
//	freopen("1200E.in","r",stdin);
	cin>>n;
	p1[0]=p2[0]=1;
	for (int i=1;i<=1000000;i++){
		p1[i]=p1[i-1]*67;p1[i]%=mod1;
		p2[i]=p2[i-1]*67;p2[i]%=mod2;
	}
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		len[i]=strlen(s+1);
		int x=0,now1=0,now2=0;
		for (int j=1;j<=min(len[i],tot);j++){
			now1=now1*67+value(s[j]);now1%=mod1;
			now2=now2*67+value(s[j]);now2%=mod2;
			if (gethash1(tot-j+1,tot)==now1&&gethash2(tot-j+1,tot)==now2)x=max(x,j);
		}
		for (int j=x+1;j<=len[i];j++){
			ans[++tot]=s[j];
			hash1[tot]=hash1[tot-1]*67+value(s[j]);hash1[tot]%=mod1;
			hash2[tot]=hash2[tot-1]*67+value(s[j]);hash2[tot]%=mod2;
		}
	}
	for (int i=1;i<=tot;i++)putchar(ans[i]);
	cout<<endl;
}