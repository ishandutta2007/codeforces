#include<cstdio>
#include<cstring>
const int M1=1e9+7,M2=1e9+9,M3=998244353,N=1e6+3;
char a[N],ans[N];int n,mx,s1,s2,s3,t1,t2,t3,pow1[N],pow2[N],pow3[N],len,ansl;
inline int F(char c){
	if(c>47&&c<58)return c-48;
	if(c>96)return c-97+10;
	return c-65+36;
}
signed main(){
	scanf("%d%s",&n,ans);n--;
	ansl=strlen(ans);
	pow1[0]=pow2[0]=pow3[0]=1;
	for(int i=1;i<N;i++)
	  pow1[i]=pow1[i-1]*62ll%M1,
	  pow2[i]=pow2[i-1]*62ll%M2,
	  pow3[i]=pow3[i-1]*62ll%M3;
	for(int i=1;i<=n;i++){
	  scanf("%s",a);len=strlen(a);
	  mx=-1;s1=s2=s3=t1=t2=t3=0;
	  for(int j=0;j<ansl&&j<len;j++){
		s1=(s1*62ll+F(a[j]))%M1;
		s2=(s2*62ll+F(a[j]))%M2;
		s3=(s3*62ll+F(a[j]))%M3;
		t1=(t1+1ll*pow1[j]*F(ans[ansl-j-1]))%M1;
		t2=(t2+1ll*pow2[j]*F(ans[ansl-j-1]))%M2;
		t3=(t3+1ll*pow3[j]*F(ans[ansl-j-1]))%M3;
		if(s1==t1&&s2==t2&&s3==t3)mx=j;
	  }
	  for(int j=mx+1;j<len;j++)ans[ansl++]=a[j];
	}
	printf("%s",ans);
	return 0;
}