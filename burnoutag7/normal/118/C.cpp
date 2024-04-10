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

int n,k;
string s;
int cnt[10];
string res[10];
int ans[10];

int ab(int x){
	return x>=0 ? x : -x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<s.size();i++){
		cnt[s[i]-'0']++;
	}
	for(int j=0;j<10;j++){
		res[j]=s;
	}
	
	for(int dn=0;dn<=9;dn++){
		for(int cost=1;cost<=9;cost++){
			if(cnt[dn]>=k)break;
			for(int i=0;i<s.size();i++){
				if(cnt[dn]>=k)break;
				if(res[dn][i]-'0'==cost+dn){
					cnt[dn]++;
					res[dn][i]=dn+'0';
					ans[dn]+=ab(s[i]-dn-'0');
				}
			}
			for(int i=s.size()-1;i>=0;i--){
				if(cnt[dn]>=k)break;
				if(res[dn][i]-'0'==dn-cost){
					cnt[dn]++;
					res[dn][i]=dn+'0';
					ans[dn]+=ab(s[i]-dn-'0');
				}
			}
		}
	}
	
	int an=1e9;
	string re;
	for(int i=0;i<=9;i++){
		if(an>ans[i]){
			an=ans[i];
			re=res[i];
		}else{
			if(an==ans[i]){
				if(re>res[i]){
					an=ans[i];
					re=res[i];
				}
			}
		}
	}
	
	cout<<an<<endl;
	cout<<re<<endl;
	
	return 0;
}