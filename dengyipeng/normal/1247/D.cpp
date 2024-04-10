#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define ll long long 
using namespace std;

int n,k,i,j,a[maxn],t[maxn];
int x,s1,s2;
ll ans;

int mul(int x,int k){
	int s=1;
	while (k--) {
		s=s*x;
		if (s>maxn) return -1;
	}
	return s;
}

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) {
		scanf("%d",&x),s1=s2=1;
		for(j=2;j<=sqrt(x);j++) if (x%j==0){
			int cnt=0;
			while (x%j==0) cnt++,x/=j;
			s1*=mul(j,cnt%k);
			if (s2>0) s2*=mul(j,(k-cnt%k)%k);
		}
		if (x){
			s1*=x;
			if (s2>0) s2*=mul(x,k-1);
		}
		if (s2>0) ans+=t[s2];
		t[s1]++;
	}
	printf("%I64d",ans);
}