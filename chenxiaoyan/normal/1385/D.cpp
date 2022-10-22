/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200000,LET=20;
int n;
char a[N+5];
int dp[N<<2][LET];
int dfs(int l=1,int r=n,int c=0,int p=1){// 
	if(l==r)return a[l]!='a'+c;
	if(~dp[p][c])return dp[p][c]; 
	int &res=dp[p][c],mid=l+r>>1,sum1=0,sum2=0;
	for(int i=l;i<=mid;i++)sum1+=a[i]!='a'+c;
	for(int i=mid+1;i<=r;i++)sum2+=a[i]!='a'+c;
	res=min(sum1+dfs(mid+1,r,c+1,p<<1|1),sum2+dfs(l,mid,c+1,p<<1));// 
//	printf("dp[%d][%d][%d]=%d\n",l,r,c,res);
	return res;
}
void mian(){
	cin>>n;
	scanf("%s",a+1);
	for(int i=1;i<=4*n;i++)for(int j=0;j<LET;j++)dp[i][j]=-1;// 
	cout<<dfs()<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}