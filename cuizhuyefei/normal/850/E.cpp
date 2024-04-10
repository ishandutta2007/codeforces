#include<cstdio>
#define rep(i,a,b) for(register int i=a;i<=b;i++)
const int mo = 1e9+7,N = 1111111,inv2 = 5e8+4;
int n,all,v[N],a[N],cnt[N],mi[22],res;char t[N];
int main(){
	scanf("%d",&n);all=(1<<n)-1;scanf("%s",t);rep(i,0,all)v[i]=t[i]-'0';
//	rep(i,0,all)rep(j,0,all)a[i^j]+=v[i]*v[j];//XOR
	for(int j=2;j<=(1<<n);j<<=1)
		for(int i=0;i<(1<<n);i+=j)rep(k,0,(j>>1)-1){
			int x=v[i+k],y=v[i+k+(j>>1)];v[i+k]=x+y<mo?x+y:x+y-mo;
			v[i+k+(j>>1)]=x-y>=0?x-y:x-y+mo;
		}
	rep(i,0,all)a[i]=1LL*v[i]*v[i]%mo;
	for(int j=2;j<=(1<<n);j<<=1)
		for(int i=0;i<(1<<n);i+=j)rep(k,0,(j>>1)-1){
			int x=a[i+k],y=a[i+k+(j>>1)];a[i+k]=1LL*(x+y)*inv2%mo;
			a[i+k+(j>>1)]=1LL*(x-y+mo)*inv2%mo;
		}
	mi[0]=1;rep(i,1,n)mi[i]=mi[i-1]<<1;
	rep(i,1,all)cnt[i]=cnt[i>>1]+(i&1);
	rep(i,0,all)res=(res+1LL*mi[n-cnt[i]]*a[i])%mo;
	res=3LL*res%mo;printf("%d",res);
	return 0;
}