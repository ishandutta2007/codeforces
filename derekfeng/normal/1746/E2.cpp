#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int S=100;
int n,dp[104][104];pii fr[104][104];
bool ask(vector<int>&v){
	printf("? %d",(int)v.size());
	for(auto x:v)printf(" %d",x);puts("");fflush(stdout);
	char buf[10];scanf("%s",buf);return *buf=='Y';
}
void init(){
	memset(dp,0x3f,sizeof(dp));
	for(int s=0;s<=S;s++){
		for(int A=0;A<=s;A++){
			int B=s-A;if(s<3)dp[A][B]=0;
			else for(int a=0;a<=A;a++)for(int b=0;b<=B;b++){
				int w=max(dp[a+b][A-a],dp[A-a+B-b][a])+1;
				if(w<dp[A][B])dp[A][B]=w,fr[A][B]={a,b};
			}
		}
	}
}
void getans(vector<int>&v){
	for(auto x:v){
		printf("! %d\n",x);fflush(stdout);
		char buf[10];scanf("%s",buf);
		if(buf[1]==')')return;
	}
}
void solve(vector<int>vA,vector<int>vB){
	int A=vA.size(),B=vB.size();
	if(A+B<3){
		vector<int>v;
		for(auto x:vA)v.push_back(x);
		for(auto x:vB)v.push_back(x);
		getans(v);return;
	}
	int a,b;
	if(A+B<=S)a=fr[A][B].fi,b=fr[A][B].se;
	else a=A/2,b=B/2;
	vector<int>v,vv;
	for(int i=0;i<a;i++)v.push_back(vA[i]);
	for(int i=0;i<b;i++)v.push_back(vB[i]);
	bool t=ask(v);
	if(t)for(int i=a;i<A;i++)vv.push_back(vA[i]);
	else{
		v.clear();
		for(int i=a;i<A;i++)v.push_back(vA[i]);
		for(int i=b;i<B;i++)v.push_back(vB[i]);
		for(int i=0;i<a;i++)vv.push_back(vA[i]);
	}
	solve(v,vv);
}
int main(){
	init(),scanf("%d",&n);vector<int>vec;
	for(int i=1;i<=n;i++)vec.push_back(i);
	solve(vec,{});
}