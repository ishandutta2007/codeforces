#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
const int Mod1=998244353,Mod2=1004535809,B1=5,B2=7;

int n; char s[200010]; int tot[200010],seq[200010],seqtot;  //pos
int p1[200010],p2[200010],h1[200010],h2[200010],h3[200010],h4[200010];
int gethash(int l,int r,int *h,int *p,int Mod){
	return ( (h[r]-1LL*h[l-1]*p[r-l+1])%Mod+Mod)%Mod;
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++){
		tot[i]=tot[i-1];
		if (s[i]=='0') tot[i]++,seq[++seqtot]=i;
	}
	p1[0]=p2[0]=1; 
	for (int i=1;i<=seqtot;i++){
		p1[i]=1LL*p1[i-1]*B1%Mod1;
		p2[i]=1LL*p2[i-1]*B2%Mod2;
		h1[i]=(1LL*h1[i-1]*B1+(seq[i]&1)+1)%Mod1;
		h2[i]=(1LL*h2[i-1]*B2+(seq[i]&1)+1)%Mod2;
		h3[i]=(1LL*h3[i-1]*B1+2-(seq[i]&1))%Mod1;
		h4[i]=(1LL*h4[i-1]*B2+2-(seq[i]&1))%Mod2;
	}
	int q=read();
	while (q--){
		int x=read(),y=read(),len=read();
		if (tot[x+len-1]-tot[x-1]!=tot[y+len-1]-tot[y-1]){puts("NO");continue;}
		if (tot[x+len-1]-tot[x-1]==0){puts("YES");continue;}
		int l1=lower_bound(seq+1,seq+seqtot+1,x)-seq,r1=l1+tot[x+len-1]-tot[x-1]-1;
		int l2=lower_bound(seq+1,seq+seqtot+1,y)-seq,r2=l2+tot[y+len-1]-tot[y-1]-1;
		int a=(x&1?gethash(l1,r1,h1,p1,Mod1):gethash(l1,r1,h3,p1,Mod1));
		int b=(x&1?gethash(l1,r1,h2,p2,Mod2):gethash(l1,r1,h4,p2,Mod2));
		int c=(y&1?gethash(l2,r2,h1,p1,Mod1):gethash(l2,r2,h3,p1,Mod1));
		int d=(y&1?gethash(l2,r2,h2,p2,Mod2):gethash(l2,r2,h4,p2,Mod2));
		if (a==c&&b==d) puts("YES");
		else puts("NO");
	}
	return 0;
}