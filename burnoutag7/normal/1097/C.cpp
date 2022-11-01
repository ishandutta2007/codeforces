/******************
*  Author: BD747  *
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
#include<bits/stdc++.h>
using namespace std;

map<int,int> fr,mid,ba;
int n;
int ans;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		int cnt=0;
		bool back=false,front=false;
		for(int j=0;j<s.size();j++){
			if(s[j]=='('){
				cnt++;
			}else{
				cnt--;
			}
			if(cnt<0){
				back=true;
			}
		}
		cnt=0;
		for(int j=s.size()-1;j>=0;j--){
			if(s[j]=='('){
				cnt++;
			}else{
				cnt--;
			}
			if(cnt>0){
				front=true;
			}
		}
		if(back&&front){
			continue;
		}
		if(cnt<0){
			ba[cnt]++;
		}
		if(cnt>0){
			fr[cnt]++;
		}
		if(cnt==0){
			mid[cnt]++;
		}
	}
	for(map<int,int>::iterator it=fr.begin();it!=fr.end();it++){
		map<int,int>::iterator rit=ba.find((-(it->first)));
		if(rit==ba.end()){
			continue;
		}
		ans+=min((rit->second),(it->second));
	}
	for(map<int,int>::iterator it=mid.begin();it!=mid.end();it++){
		ans+=(it->second)/2;
	}
	cout<<ans<<endl;

	return 0;
}