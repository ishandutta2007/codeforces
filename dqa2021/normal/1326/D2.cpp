#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
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
typedef long long ll;
const int M1=998244353,M2=1004535809,B1=29,B2=31;


char s[1000010]; int n;
int p1[1000010],p2[1000010],h1[1000010],h2[1000010],h3[1000010],h4[1000010];
void init()
{
}
int gethash(int *p,int *h,int l,int r,int Mod){
	return ((h[r]-1LL*h[l-1]*p[r-l+1])%Mod+Mod)%Mod;
}
void solve()
{
	scanf("%s",s+1); n=strlen(s+1);
	p1[0]=p2[0]=1;
	for (int i=1;i<=n;i++){
		p1[i]=1LL*p1[i-1]*B1%M1;
		p2[i]=1LL*p2[i-1]*B2%M2;
		h1[i]=(1LL*h1[i-1]*B1+s[i]-'a'+1)%M1;
		h2[i]=(1LL*h2[i-1]*B2+s[i]-'a'+1)%M2;
		h3[i]=(1LL*h3[i-1]*B1+s[n-i+1]-'a'+1)%M1;
		h4[i]=(1LL*h4[i-1]*B2+s[n-i+1]-'a'+1)%M2;
	}
	int lmax=0,rmax=n+1,ans=1,lans=1,rans=n+1;
	while (lmax<n&&s[lmax+1]==s[rmax-1]) lmax++,rmax--;
	if (lmax==n) return printf("%s\n",s+1),void();
	ans=lmax*2,lans=lmax,rans=rmax;
	for (int i=1;i<=n;i++){
		int l=1,r=n,mid;
		while (l<r){
			mid=l+r+1>>1;
			if (i-mid+1>0&&i+mid-1<=n&&gethash(p1,h1,i-mid+1,i+mid-1,M1)==gethash(p1,h3,(n-i+1)-mid+1,(n-i+1)+mid-1,M1)&&
									gethash(p2,h2,i-mid+1,i+mid-1,M2)==gethash(p2,h4,(n-i+1)-mid+1,(n-i+1)+mid-1,M2))
										l=mid;
			else r=mid-1;
		}
		int L=i-l+1,R=i+l-1;
//		printf("get %d %d\n",L,R);
		if (L<=n-R+1&&L-1<=lmax&&(L-1)*2+l*2-2+1>ans) ans=(L-1)*2+l*2-2+1,lans=R,rans=n-(L-1)+1;
//		printf("test ans %d\n",ans);
		if (L>=n-R+1&&R+1>=rmax&&(n-(R+1)+1)*2+l*2-2+1>ans) ans=(n-(R+1)+1)*2+l*2-2+1,lans=n-(R+1)+1,rans=L;
//		printf("test ans %d\n",ans);
		if (i==n||s[i]!=s[i+1]) continue;
		l=1,r=n,mid;
		while (l<r){
			mid=l+r+1>>1;
			if (i-mid+1>0&&i+mid<=n&&gethash(p1,h1,i-mid+1,i+mid,M1)==gethash(p1,h3,(n-i+1)-mid,n-i+mid,M1)&&
									gethash(p2,h2,i-mid+1,i+mid,M2)==gethash(p2,h4,(n-i+1)-mid,(n-i)+mid,M2))
										l=mid;
			else r=mid-1;
		}
		L=i-l+1,R=i+l;
//		printf("get %d %d\n",L,R);
		if (L<=n-R+1&&L-1<=lmax&&(L-1)*2+l*2>ans) ans=(L-1)*2+l*2,lans=R,rans=n-(L-1)+1;
//		printf("test ans %d\n",ans);
		if (L>=n-R+1&&R+1>=rmax&&(n-(R+1)+1)*2+l*2>ans) ans=(n-(R+1)+1)*2+l*2,lans=n-(R+1)+1,rans=L;
//		printf("test ans %d\n",ans);
	}
//	printf("lans %d rans %d\n",lans,rans);
	for (int i=1;i<=lans;i++) putchar(s[i]);
	for (int i=rans;i<=n;i++) putchar(s[i]);
	puts("");
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}