#include<bits/stdc++.h>
using namespace std;
 
void solve(){
	int n,res=0;cin>>n;
	string s;cin>>s;
	if(is_sorted(s.begin(),s.end())){cout<<0<<endl;return;} 
	
	int _0=count(s.begin(),s.end(),'0'),_1=n-_0;
	if(_0<_1){swap(_0,_1);reverse(s.begin(),s.end());for(auto&x:s)x='0'+'1'-x;}
	
	vector<int> mx(n+1);
	for(int i=0,ns=0;i<n;i++){
		ns+=s[i]-'0'?-1:1;
		if(ns>=0)mx[ns]=i;
	}
	int delta=_0-_1,nw=0;
	while(nw<n&&s[nw]=='0')nw++;
	while(nw<delta){
		res++;
		nw+=(mx[nw]+1-nw)/2;
	}
	cout<<res+1<<endl;
}
 
main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}