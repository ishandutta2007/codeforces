#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const int M=15000005;
int n,m;
int cnt[M];
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
int pri[N],len;
int a[N];
bool np[N];
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ll g=0;
	for(i=1;i<=n;i++) g=gcd(g,a[i]);
	for(i=1;i<=n;i++) a[i]/=g;
	for(i=2;i<=3873;i++){
		if(!np[i]) pri[++len]=i;
		for(j=i+i;j<=3873;j+=i) np[j]=1;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=len;j++){
			if(pri[j]*ll(pri[j])>a[i]) break;
			if(a[i]%pri[j]==0) cnt[pri[j]]++;
			while(a[i]%pri[j]==0) a[i]/=pri[j];
		}
		if(a[i]>1) cnt[a[i]]++;
	}
	int mn=n;
	for(i=0;i<M;i++)
		mn=min(mn,n-cnt[i]);
	if(mn==n) cout<<-1;
	else cout<<mn;
	return 0;
}