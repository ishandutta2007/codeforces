#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int T,n,a[100005];
int q,l[1000],r[1000],f[1000],dp[1000],nf[1000],ndp[1000],res;
int p,L[1000],R[1000],ans[1000];
void getind(int x,int &m,int *L,int *R,int *ans){
	m=0;
	for(int l=1;l<=x;){
		int c=x/l,r=x/c;
		if(x%l!=0)L[++m]=c,R[m]=c+1,ans[m]=l-1;
		if(x%r==0)L[++m]=c,R[m]=c,ans[m]=r-1;
		l=r+1;
	}
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	q=0,res=0;
	for(int i=n;i;i--){
		getind(a[i],p,L,R,ans);
		for(int i=1;i<=p;i++)nf[i]=ndp[i]=0;
		int cur=1;
		for(int i=1;i<=p;i++){
			int sf=0,sdp=0;
			while(cur<=q&&l[cur]>=R[i]){
				(sf+=f[cur])%=M,(sdp+=dp[cur])%=M;
				cur++;
			}
			nf[i]=((ll)sdp*ans[i]+sf)%M,ndp[i]=sdp;
		}
		ndp[1]++;
		for(int i=1;i<=p;i++){
			(res+=nf[i])%=M;
			l[i]=L[i],r[i]=R[i],f[i]=nf[i],dp[i]=ndp[i];
		}
		q=p;
	}
	printf("%d\n",res);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}