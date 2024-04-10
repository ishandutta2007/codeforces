#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+5;
const LL base=23333,P=998244853;
struct range{int l,r;}a[N];
int n,len,ans[N];LL hs[N],pw[N];char str[N];
LL calc(int l,int r){return ((hs[r]-(LL)hs[l-1]*pw[r-l+1]%P)%P+P)%P;}
bool check(int l,int r,int len){
	if(len==-1)return true;
	return calc(l,l+len-1)==calc(r-len+1,r);
}
int main(){
	scanf("%d",&n);scanf("%s",str+1);pw[0]=1;
	for(int i=1;i<=n;i++)hs[i]=((LL)hs[i-1]*base%P+str[i])%P,pw[i]=(LL)pw[i-1]*base%P;
	for(int i=1,now=(n&1)?n:n-1;i<=n;i++,now-=2){
		if(i>n-i+1)continue;
		a[++len]=(range){i,n-i+1};
	}
	reverse(a+1,a+len+1);
	if(a[1].l==a[1].r)ans[1]=-1;else ans[1]=(str[a[1].l]==str[a[1].r])?1:-1;
	for(int i=2;i<=len;i++)for(int j=ans[i-1]+2;j>=-1;j-=2)
		if(check(a[i].l,a[i].r,j)){ans[i]=j;break;}
	for(int i=len;i;i--)printf("%d%c",ans[i]," \n"[i==1]); 
	return 0;
}