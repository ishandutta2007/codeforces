/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=250,M=250,LET=26;
int n,m;
char a[N+1][M+5];
vector<int> cnt[N+1];
int odd[N+1];
int s;
vector<int> b[2*N+2];
bool ok[2*N+2];
void sep(){
	b[s=1]=vector<int>(LET,0);ok[s]=true;
	for(int i=1;i<=n;i++)b[++s]=cnt[i],ok[s]=odd[i]<=1,b[++s]=vector<int>(LET,0),ok[s]=true;
}
bool eq(int x,int y){return ok[x]&&ok[y]&&b[x]==b[y];}
int rds[2*N+2];
void manacher(){
	int mid=0,r=0;
	for(int i=1;i<=s;i++)
		if(r<i){
			rds[i]=0;
			while(i-rds[i]>=1&&i+rds[i]<=s&&eq(i-rds[i],i+rds[i]))rds[i]++;
			mid=i;r=i+rds[i]-1;
		}
		else if(i+rds[2*mid-i]<=r)rds[i]=rds[2*mid-i];
		else{
			rds[i]=r-i+1;
			while(i-rds[i]>=1&&i+rds[i]<=s&&eq(i-rds[i],i+rds[i]))rds[i]++;
			mid=i;r=i+rds[i]-1;
		}
}
signed main(){
//	freopen("C:\\Users\\chenx\\OneDrive\\\\data.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]+1;
	for(int i=1;i<=n;i++)cnt[i].resize(LET);
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<LET;k++)cnt[j][k]=0;
			odd[j]=0;
		}
		for(int j=i;j<=m;j++){
			for(int k=1;k<=n;k++)odd[k]+=++cnt[k][a[k][j]-'a']&1?1:-1;
			sep();
			manacher();
			for(int k=1;k<=2*n+1;k++)ans+=rds[k]>>1;
		}
	}
	cout<<ans;
	return 0;
}