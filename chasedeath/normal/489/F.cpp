#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

int IO;
int rd(){
	int s=0;
	while((IO=getchar())<48);
	do s=(s<<1)+(s<<3)+(IO^'0');
	while((IO=getchar())>47);
	return s;
}

const int N=510;
ll P;

int n,m;
int c[N];
ll dp[N][N];
int cnt[3];

ll dfs(int cnt1,int cnt2){
	if(cnt1>n||cnt2>n) return 0;
	if(cnt1<0||cnt2<0) return 0;
	//cout<<cnt1<<' '<<cnt2<<endl;
	if(cnt1==cnt[1]&&cnt[2]==cnt2) return 1;
	if(~dp[cnt1][cnt2]) return dp[cnt1][cnt2];
	ll res=(cnt1+2)*(cnt1+1)/2*dfs(cnt1+2,cnt2)%P+cnt1*(cnt2+1)*dfs(cnt1,cnt2+1)%P+(cnt2+2)*(cnt2+1)/2*dfs(cnt1-2,cnt2+2);
	return dp[cnt1][cnt2]=res%P;
}







int main(){
	n=rd(),m=rd(),P=rd();
	rep(i,1,m) rep(j,1,n) {
		int x; scanf("%1d",&x);
		c[j]+=x;
	}
	memset(dp,-1,sizeof dp);
	rep(i,1,n) cnt[2-c[i]]++;
	//dp[cnt[1]][cnt[2]]=1;
	/*drep(i,cnt[1],0) {
		drep(j,cnt[2],0) {
			if(i>=2) (dp[i-2][j]+=dp[i][j])%=P;
			if(j>=1) (dp[i][j-1]+=dp[i][j])%=P;
			(dp[i+2][j-2]+=dp[i][j])%=P;
		}
	}*/
	//cout<<cnt[1]<<' '<<cnt[2]<<endl;
	printf("%lld\n",dfs(0,0));
}