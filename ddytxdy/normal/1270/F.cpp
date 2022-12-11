#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50,M=1e8;
char s[N];int n,a[N],cnt[M],B,st[N],tp,nxt[N];LL ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);B=sqrt(n);
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+s[i]-'0';
	for(int i=n,p=n+1;~i;i--){
		nxt[i]=p;
		if(s[i]=='1')p=i;
	}
	for(int i=1;i<=B;i++){
		while(tp)cnt[st[tp--]]=0;
		for(int j=0;j<=n;j++){
			int d=i*a[j]-j+n;
			ans+=cnt[d];cnt[d]++;st[++tp]=d;
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=nxt[i],p=1;j<=n&&(B+1)*p<=n;j=nxt[j],p++){
			int l=(j-i+p-1)/p,r=(nxt[j]-1-i)/p;
			l=max(l,B+1);ans+=max(0,r-l+1);
		}
	}
	cout<<ans;
	return 0;
}