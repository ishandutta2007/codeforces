#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int n,i,j,k,dp[5005][5005];
map<int,int> s[5005];
int x[5005],t[5005];
void upd(int x,int a,int b){
	if(!dp[x][0]){
		dp[x][0]=1;
		s[x].clear();
	}
	map<int,int>::iterator it=s[x].upper_bound(a);
	int t=a;
	if(it!=s[x].begin()){
		it--;
		if(it->second<b){
			t=it->first;
			it->second=b;
		}
		else return;
	}
	else{
		s[x][a]=b;
	}
	it=s[x].upper_bound(a);
	while(it!=s[x].end()){
		if(it->first<=b+1){
			b=max(b,it->second);
			s[x].erase(it->first);
			s[x][t]=b;
			it=s[x].upper_bound(a);
		}
		else{
			break;
		}
	}
}
int query(int x,int y){
	int ans=0x7fffffff;
	map<int,int>::iterator it=s[x].upper_bound(y);
	if(it!=s[x].end()){
		if(it->first<=y&&y<=it->second) return 0;
		ans=min(ans,abs(y-it->first));
		ans=min(ans,abs(y-it->second));
	}
	if(it!=s[x].begin()){
		it--;
		if(it->first<=y&&y<=it->second) return 0;
		ans=min(ans,abs(y-it->first));
		ans=min(ans,abs(y-it->second));
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d%d",&t[i],&x[i]);
	}
	upd(0,0,0);
	for(i=0;i<n;i++){
		int rem=t[i+1]-t[i];
		for(j=0;j<=n;j++)if(dp[i][j]){
			if(1<=j&&j<i) continue;
			if(i==j&&j!=0)continue;
			if(j>i+1){
				int tl=x[i]-rem,tr=x[i]+rem;
				if(tl<=x[i+1]&&x[i+1]<=tr){
					dp[i+1][j]=1;
				}
			}
			if(j==i+1){
				int tl=x[i]-rem,tr=x[i]+rem;
				upd(i+1,tl,tr);
			}
			if(j==0){
				dzd(s[i],it){
					int li=it->first,ri=it->second;
					int tl=li-rem,tr=ri+rem;
					if(tl<=x[i+1]&&x[i+1]<=tr){
						int rem2=rem-(li<=x[i+1]&&x[i+1]<=ri?0:min(abs(x[i+1]-li),abs(x[i+1]-ri)));
						upd(i+1,x[i+1]-rem2,x[i+1]+rem2);
					}
				}
				for(k=i+2;k<=n;k++){
					int rem2=rem-query(i,x[k]);
					if(abs(x[i+1]-x[k])<=rem2){
						dp[i+1][k]=1;
					}
				}
			}
		}
	}
	int ans=0;
	for(i=0;i<=n;i++) ans|=dp[n][i];
	cout<<(ans?"YES":"NO")<<endl;
	return 0;
}