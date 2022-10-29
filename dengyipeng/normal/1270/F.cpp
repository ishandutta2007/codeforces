#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#define maxn 200005
#define ll long long 
using namespace std;

int n,s[maxn],i,j,k,K,p[maxn],tot;
ll ans; char ch;
map<int,int> m;

int min(int a,int b){return (a<b)?a:b;}

int main(){
	for(ch=getchar();ch>='0'&&ch<='1';ch=getchar()) {
		s[++n]=ch-'0',s[n]+=s[n-1];
		if (ch-'0') p[++tot]=n;
	}
	p[++tot]=n+1;
	K=sqrt(1.0*n/log2(n));
	for(k=1;k<=K;k++){
		m[0]=1;
		for(i=1;i<=n;i++) {
			ans+=m[i-s[i]*k];
			m[i-s[i]*k]++;
		}
		m.clear();
	}
	for(i=0;i<n;i++){
		for(j=1;j<=n/K&&s[i]+j<=tot;j++){
			int l=p[s[i]+j]-1,r=p[s[i]+j+1]-1;
			int L=max((l-i)/j,K),R=(r-i)/j;
			if (L<R) 
				ans+=R-L;
		}
	}
	printf("%lld",ans);
}