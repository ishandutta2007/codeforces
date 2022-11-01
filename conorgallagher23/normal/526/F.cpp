#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+5;
int n,p[N],sl[N],sr[N],cnt[N],mi[N],ma[N];LL ans;
void solve(int *a,int *b){
	int la=a[0],lb=b[0],nowmi,nowma;
	mi[0]=nowmi=n+1;ma[0]=nowma=0;
	for(int i=1;i<=lb;i++)mi[i]=min(mi[i-1],b[i]),ma[i]=max(ma[i-1],b[i]);
	for(int i=1,nl=1,nr=1,len;i<=la;i++){
		nowmi=min(nowmi,a[i]);nowma=max(nowma,a[i]);len=nowma-nowmi+1;
		if(len>i&&len-i<=lb&&mi[len-i]>nowmi&&ma[len-i]<nowma)ans++;
		while(nr<=lb&&mi[nr]>nowmi)cnt[ma[nr]-nr+1]++,nr++;
		while(nl<nr&&ma[nl]<nowma)cnt[ma[nl]-nl+1]--,nl++;
		ans+=(LL)cnt[i+nowmi];
	}
	for(int i=1;i<=lb;i++)cnt[ma[i]-i+1]=0;
}
void cdq(int l,int r){
	if(l==r){ans++;return;}
	int mid=(l+r)>>1;sl[0]=sr[0]=0;
	for(int i=mid;i>=l;i--)sl[++sl[0]]=p[i];
	for(int i=mid+1;i<=r;i++)sr[++sr[0]]=p[i];
	solve(sl,sr);solve(sr,sl);
	cdq(l,mid);cdq(mid+1,r);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++)scanf("%d%d",&x,&y),p[x]=y;
	cdq(1,n);
	printf("%lld\n",ans); 
	return 0;
}