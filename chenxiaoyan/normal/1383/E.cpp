/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
#define mp make_pair
const int mod=1000000007;
const int N=1000000;
int n;
char a[N+5]; 
vector<pair<int,bool> > v;
int dp[N+1];
pair<pair<int,int>,int> stk[N];int top;
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1,ie;i<=n;i=ie+1){
		ie=i;while(ie+1<=n&&a[ie+1]==a[i])ie++;
		v.pb(mp(ie-i+1,a[i]^48));
	}
//	reverse(v.begin(),v.end());
	int sum=0,now=0,las=!v.back().Y*v.back().X;
	dp[v.size()]=1;
	for(int i=v.size()-1;~i;i--){
		if(v[i].Y==0){
			dp[i]=1ll*v[i].X*dp[i+1]%mod;
			while(top&&stk[top-1].X.Y<=v[i].X)(now-=1ll*(stk[top-1].X.Y-stk[top-1].X.X+1)*stk[top-1].Y%mod)%=mod,top--;
			if(top)(now-=1ll*(v[i].X+1-stk[top-1].X.X)*stk[top-1].Y%mod)%=mod,stk[top-1].X.X=v[i].X+1;
			stk[top++]=mp(mp(1,v[i].X),(i<v.size()-1)*dp[i+1]),(now+=(i<v.size()-1)*dp[i])%=mod;
//			for(int j=0;j<top;j++)printf("[%d,%d]:%d ",stk[j].X.X,stk[j].X.Y,stk[j].Y);puts("");
		}
		else
			dp[i]=(sum+=1ll*v[i].X*(now+1+las)%mod)%=mod;
//		cout<<dp[i]<<"\n";
	}
	if(v.size()==1)cout<<(dp[0]+mod)%mod;
	else if(v[0].Y==1)cout<<(dp[0]+mod)%mod;
	else cout<<((dp[0]+dp[1])%mod+mod)%mod;
	return 0;
}