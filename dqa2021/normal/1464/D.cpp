#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;
const int mod=1e9+7;

int n,p[1000010];
bool vis[1000010];
int check(int n,int tot1,int tot2,int tot3){
	int res=0;
	if (n%3==0){
		if (tot1>tot2) res+=tot2+(tot1-tot2)/3*2;
		else{
			res+=tot1; tot2-=tot1,tot1=0;
			res+=tot2;
		}
		return res;
	}
	if (n%3==1){
		res=1e9; int t;
		if (tot1>=4){
			t=2+check(n-4,tot1-4,tot2,tot3);
			res=min(res,t);
		}
		if (tot1>=2&&tot2){
			t=1+check(n-4,tot1-2,tot2-1,tot3);
			res=min(res,t);
		}
		if (tot2>=2){
			t=check(n-4,tot1,tot2-2,tot3);
			res=min(res,t);
		}
		if (tot1&&tot3){
			t=2+check(n-4,tot1-1,tot2,tot3-1);
			res=min(res,t);
		}
		return res;
	}
	res=1e9;
	if (tot1>=2) res=min(res,1+check(n-2,tot1-2,tot2,tot3));
	if (tot2) res=min(res,check(n-2,tot1,tot2-1,tot3));
	return res;
}
void init(){
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++) p[i]=read(),vis[i]=0;
	int ans=1;
	if (n%3==0){
		for (int i=1;i<=n;i+=3) ans=3LL*ans%mod;
	}
	else if (n%3==1){
		for (int i=5;i<=n;i+=3) ans=3LL*ans%mod;
		ans=4LL*ans%mod;
	}
	else{
		for (int i=3;i<=n;i+=3) ans=3LL*ans%mod;
		ans=2*ans%mod;
	}
	printf("%d ",ans);
	int B=0;
	int tot1=0,tot2=0,tot3=0,tot4=0;
	for (int i=1;i<=n;i++){
		if (vis[i]) continue;
		int tot=0;
		for (int j=i;!vis[j];vis[j]=1,j=p[j]) tot++;
		while (tot>4) tot-=3,tot3++,B++;
		if (tot==1) tot1++;
		if (tot==2) tot2++;
		if (tot==3) tot3++;
		if (tot==4) tot4++;
	}
	//printf("test %d %d %d %d\n",tot1,tot2,tot3,tot4);
	ans=1e9;
	for (int i=0;i<=tot3&&i<=1;i++)
		for (int j=0;j<=tot4;j++){
			ans=min(ans,B+tot4+i+check(n,tot1+i+j,tot2+i+(tot4-j)*2,tot3-i+j));
			//printf("check %d %d %d = %d\n",tot1+i+j,tot2+i+(tot4-j)*2,tot3-i+j,check(n,tot1+i+j,tot2+i+(tot4-j)*2,tot3-i+j));
		}
	/*if (n%3==1){
		
	}*/
	if (n%3==1&&tot4){
		tot4--,n-=4;
		for (int i=0;i<=tot3&&i<=1;i++)
			for (int j=0;j<=tot4;j++){
				ans=min(ans,B+tot4+i+check(n,tot1+i+j,tot2+i+(tot4-j)*2,tot3-i+j));
				//printf("check %d %d %d = %d\n",tot1+i+j,tot2+i+(tot4-j)*2,tot3-i+j,check(n,tot1+i+j,tot2+i+(tot4-j)*2,tot3-i+j));
			}
		tot4++,n+=4;
	}
	if (n%3==1&&tot1&&tot3){
		tot1--,tot3--,n-=4,B++;
		for (int i=0;i<=tot3&&i<=1;i++)
			for (int j=0;j<=tot4;j++){
				ans=min(ans,B+tot4+i+check(n,tot1+i+j,tot2+i+(tot4-j)*2,tot3-i+j));
				//printf("check %d %d %d = %d\n",tot1+i+j,tot2+i+(tot4-j)*2,tot3-i+j,check(n,tot1+i+j,tot2+i+(tot4-j)*2,tot3-i+j));
			}
		tot1++,tot3++,n+=4,B--;
	}
	printf("%d\n",ans);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}