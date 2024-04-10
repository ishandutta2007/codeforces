// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)

int n,L;
long long A[200005],B[600005];
bool chk(int dt){
	auto chk=[&](int a,int b){return A[a]-dt<=B[b]&&B[b]<=A[a]+dt;};
	int lo=-1e9,hi=1e9;
	int l=0,r=0,m=3*n;
	rep(i,n){
		int tc=0;
		while(!chk(i,l)&&tc!=m)(++l)%=m,tc++;
		if(tc==m)return 0;
		while((!chk(i,r))||chk(i,(r+1)%m))(++r)%=m;
		lo=max(lo,l-i);hi=min(hi,r-i);
		if(lo>hi)return 0;
	}
	return 1;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>L;
	rep(i,n)cin>>A[i];sort(A,A+n);
	rep(i,n)cin>>B[i],B[i+n]=B[i]-L,B[i+2*n]=B[i]+L;sort(B,B+3*n);
	int low=0,high=L,ans=0;
	while(low<=high){
		int mid=(low+high)/2;
		if(chk(mid))ans=mid,high=mid-1;
		else low=mid+1;
	}
	cout<<ans<<endl;
}