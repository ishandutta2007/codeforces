#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,P,G,a[10005];
int p[7000],tot,ans;
int myp(int x,int t){
	int ans=1;
	for(;t;t>>=1,x=(ll)x*x%P)if(t&1)ans=(ll)ans*x%P;
	return ans;
}
void calc(){
	for(int i=1;i*i<=P-1;i++)if((P-1)%i==0){
		p[++tot]=i;
		if(i*i!=P-1)p[++tot]=(P-1)/i;
	}
	sort(p+1,p+tot+1);
}
int f[7000];
bool ok[7000];
int main(){
	scanf("%d%d%d",&n,&m,&P),G=P-1;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	while(m--){
		int x;scanf("%d",&x);
		G=__gcd(x,G);
	}
	calc();
	for(int i=0;i<n;i++){
		int A=myp(a[i],G);
		for(int j=1;j<=tot;j++)if(myp(A,p[j])==1){
			for(int k=1;k<=tot;k++)if((P-1)/p[j]==p[k]){
				ok[k]=1;break;
			}
			break;
		}
	}
	for(int i=tot;i;i--){
		f[i]=(P-1)/p[i];
		for(int j=i+1;j<=tot;j++)if(p[j]%p[i]==0)
			f[i]-=f[j];
	}
	for(int i=1;i<=tot;i++){
		if(!ok[i])
			for(int j=1;j<i;j++)if(ok[j]&&p[i]%p[j]==0){
				ok[i]=1;break;
			}
		if(ok[i])ans+=f[i];
	}
	printf("%d\n",ans);
}