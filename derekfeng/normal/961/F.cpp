#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int H1=257,M1=1e9+7,H2=773,M2=19260817;
int h1[1000005],h2[1000005],p1[1000005],p2[1000005];
pii qry(int l,int r){
	int f1=(h1[r]+M1-(ll)h1[l-1]*p1[r-l+1]%M1)%M1;
	int f2=(h2[r]+M2-(ll)h2[l-1]*p2[r-l+1]%M2)%M2;
	return {f1,f2};
}
int n,ans[500005];
char s[1000005];
int main(){
	scanf("%d%s",&n,s+1);
	p1[0]=p2[0]=1;
	for(int i=1;i<=n;i++){
		p1[i]=(ll)p1[i-1]*H1%M1;
		p2[i]=(ll)p2[i-1]*H2%M2;
		h1[i]=((ll)h1[i-1]*H1+s[i])%M1;
		h2[i]=((ll)h2[i-1]*H2+s[i])%M2;
	}
	for(int i=(n+1)/2;i;i--){
		int l=i,r=n-i+1;
		if(l==r){
			ans[i]=-1;
			continue;
		}
		if(l==r-1)ans[i]=1;
		else ans[i]=ans[i+1]+2;
		while(ans[i]>0&&(ans[i]>=r-l+1||qry(l,l+ans[i]-1)!=qry(r-ans[i]+1,r)))ans[i]-=2;
	}
	for(int i=1;i<=(n+1)/2;i++)printf("%d ",ans[i]);
}