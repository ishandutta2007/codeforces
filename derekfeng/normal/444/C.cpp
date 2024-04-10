#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=320;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,q,belong[100005];
ll a[100005];
ll ans[100005],num[320],same[320],sum[320];
void solve(int l,int r,int x){
	for(int i=l;i<=r;i++){
            if(same[belong[i]]){
                for(int j=(belong[i]-1)*M+1;j<=belong[i]*M;j++) a[j]=same[belong[i]];
                same[belong[i]]=0;
            }
        	sum[belong[i]]+=abs(x-a[i]);
            ans[i]+=abs(x-a[i]);
            a[i]=x;
        }
}
void upd(int l,int r,int x){
	if (belong[r]-belong[l]<2){
		solve(l,r,x);return;
	}
	solve(l,belong[l]*M,x);
	for (int i=belong[l]+1;i<belong[r];i++){
		if (same[i]) num[i]+=abs(same[i]-x),sum[i]+=1ll*M*abs(same[i]-x),same[i]=x;
		else solve((i-1)*M+1,i*M,x),same[i]=x;
	}
	solve((belong[r]-1)*M+1,r,x);
}
ll qry(int l,int r){
	ll ret=0;
	if (belong[r]-belong[l]<2){
		for (int i=l;i<=r;i++) ret+=num[belong[i]]+ans[i];
		return ret;
	}
	for (int i=l;i<=belong[l]*M;i++) ret+=num[belong[i]]+ans[i];
	for (int i=belong[l]+1;i<belong[r];i++) ret+=sum[i]; 
	for (int i=(belong[r]-1)*M+1;i<=r;i++) ret+=num[belong[i]]+ans[i];
	return ret;
}
int main(){
	int type,l,r,x;
	read(n),read(q);
	for (int i=1;i<=n;i++) a[i]=i,belong[i]=(i-1)/M+1;
	while (q--){
		read(type),read(l),read(r);
		if (type==1) read(x),upd(l,r,x);
		else write(qry(l,r)),puts("");
	}
}