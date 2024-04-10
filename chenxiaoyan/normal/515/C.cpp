#include<bits/stdc++.h>
using namespace std;
#define N 15
#define pb push_back
const int pdoffact[][8]={
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0},
	{0,0,1,1,0,0,0,0},
	{0,0,3,1,0,0,0,0},
	{0,0,3,1,1,0,0,0},
	{0,0,4,2,1,0,0,0},
	{0,0,4,2,1,0,0,1},
	{0,0,7,2,1,0,0,1},
	{0,0,7,4,1,0,0,1}
};
int pd[8];
char s[N+5];
vector<int> ans,now;
bool cmp(vector<int> &a,vector<int> &b){
	return a.size()!=b.size()?a.size()<b.size():a<b;
}
void dfs(){
	int i,j;
	int sum=0;
	for(i=2;i<=7;i++)sum+=pd[i];
	if(!sum){if(cmp(ans,now))ans=now;return;}
	for(i=now.empty()?9:now.back();i>=2;i--){
		bool ok=true;
		for(j=2;j<=7;j++)pd[j]-=pdoffact[i][j],ok&=pd[j]>=0;
		if(ok)now.pb(i),dfs(),now.pop_back();
		for(j=2;j<=7;j++)pd[j]+=pdoffact[i][j];
	}
}
int main(){
	int n,i;scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)for(int j=2;j<=7;j++)pd[j]+=pdoffact[s[i]^48][j];
	dfs();
	for(i=0;i<ans.size();i++)putchar(ans[i]+48);
	return 0;
}
/*1
4
1234
*/
/*2
3
555
*/