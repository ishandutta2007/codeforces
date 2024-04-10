/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
int lowbit(int x){return x&-x;}
int lbt(int x){return __builtin_ctz(x);}
const int N=100000;
int n,m,s;
int l[N+1],r[N+1];
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=1;i<=n;i++)
		l[i]=lower_bound(nums.begin(),nums.end(),l[i])-nums.begin(),
		r[i]=lower_bound(nums.begin(),nums.end(),r[i])-nums.begin();
}
vector<int> in[3*N+1];
vector<int> dp[3*N+1];
int main(){
	cin>>n>>m>>s;
	nums.pb(0);nums.pb(m);
	for(int i=1;i<=n;i++)scanf("%d%d",l+i,r+i),nums.pb(l[i]-1),nums.pb(r[i]);
	discrete();
	for(int i=1;i<=n;i++)for(int j=l[i];j<=r[i];j++)in[j].pb(i);
	dp[0].resize(1,0);
	for(int i=1;i<nums.size();i++){
//		printf("%d dping\n",i);
//		printf("\tin=",i);for(int j=0;j<in[i].size();j++)cout<<in[i][j]<<" ";puts("");
		dp[i].resize(1<<in[i].size());
		vector<int> mx(1<<in[i].size());
		vector<pair<int,int> > _and;
		for(int j=0;j<in[i].size();j++)for(int k=0;k<in[i-1].size();k++)if(in[i][j]==in[i-1][k])_and.pb(mp(j,k));
//		printf("\t_and=");for(int j=0;j<_and.size();j++)printf("(%d,%d) ",_and[j].X,_and[j].Y);puts("");
		vector<int> nin_and1,nin_and2;
		for(int j=0,k=0;j<in[i].size();j++)if(k>=_and.size()||(j==_and[k].X?k++,false:true))nin_and1.pb(j);
		for(int j=0,k=0;j<in[i-1].size();j++)if(k>=_and.size()||(j==_and[k].Y?k++,false:true))nin_and2.pb(j);
//		printf("\tnin_and1=");for(int j=0;j<nin_and1.size();j++)cout<<nin_and1[j]<<" ";puts("");
//		printf("\tnin_and2=");for(int j=0;j<nin_and2.size();j++)cout<<nin_and2[j]<<" ";puts("");
		vector<int> chg1(1<<_and.size(),0),chg2(1<<nin_and1.size(),0),chg3(1<<_and.size(),0),chg4(1<<nin_and2.size(),0);
		for(int j=1;j<chg1.size();j++)chg1[j]=chg1[j^lowbit(j)]|1<<_and[lbt(j)].X;
		for(int j=1;j<chg2.size();j++)chg2[j]=chg2[j^lowbit(j)]|1<<nin_and1[lbt(j)];
		for(int j=1;j<chg3.size();j++)chg3[j]=chg3[j^lowbit(j)]|1<<_and[lbt(j)].Y;
		for(int j=1;j<chg4.size();j++)chg4[j]=chg4[j^lowbit(j)]|1<<nin_and2[lbt(j)];
		for(int j=0;j<chg1.size();j++){
			int mx0=0;
			for(int k=0;k<chg4.size();k++)mx0=max(mx0,dp[i-1][chg3[j]|chg4[k]]);
			for(int k=0;k<chg2.size();k++)dp[i][chg1[j]|chg2[k]]=mx0+__builtin_parity(chg1[j]|chg2[k])*(nums[i]-nums[i-1]);
		}
//		for(int j=0;j<dp[i].size();j++)printf("\tdp[%d]=%d\n",j,dp[i][j]);
	}
	cout<<*max_element(dp[nums.size()-1].begin(),dp[nums.size()-1].end());
	return 0;
}
/*1
3 5 3
1 3
2 4
3 5
*/
/*2
1 1000 1
1 1000
*/