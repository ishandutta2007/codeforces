/******************
*  Writer: BD747  *
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

typedef long long ll;

ll n,x,y;
string s;
ll cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>x>>y;
	
	cin>>s;
	s+='1';
	
	for(ll i=0;i<n;i++){
		if(s[i]!=s[i+1] && s[i]=='0'){
			cnt++;
		}
	}
	s=s.erase(n,1);
	
	if(x<y && cnt){
		cout<<x*(cnt-1)+y<<endl;
	}else{
		cout<<y*cnt<<endl;
	}
	
	return 0;
}