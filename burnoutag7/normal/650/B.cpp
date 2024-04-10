/******************
*  Writer: Oh no  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int qz[500005];
string s;
int n,a,b,t;

int rev(int x){
	int res=0;
	res+=qz[n]-qz[x-1];
	return res;
}//OK--First 

bool check(int l,int r){
	int res=rev(l);
	res+=min((n-l+1)*a,a*(r-1));
	res+=qz[r];
	return res<=t;
}//OK--First

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>a>>b>>t;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i-1]=='w'){
			qz[i]+=b;
		}
		qz[i]+=qz[i-1]+1;
		qz[i+1]+=a;
	}//OK--First
	
	int ans=0;
	for(int i=1;i<=n;i++){
		if(t>=qz[i])ans=i;
	}//OK--First
	
	int res;
	for(int i=n;i>=2;i--){
		res=0;
		int l=1,r=n,m;
		while(l<=r){
			m=(l+r)/2;
			if(check(i,m)){
				res=m+n-i+1;
				l=m+1;
			}else{
				r=m-1;
			}
		}
		ans=max(res,ans);
	}
	
	cout<<min(ans,n)<<endl;
	
	return 0;
}