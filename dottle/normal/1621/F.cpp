#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;
 
void solve(){
	int n,a,b,c;cin>>n>>a>>b>>c;
	string s;cin>>s;
	if(n==1){
		cout<<0<<endl;
		return ;
	}
	priority_queue<int> q;
	int cnt0=0,cnt1=0,l0=0,l1=0;
	int fl=0;
	fl+=s[0]=='0';
	fl+=*s.rbegin()=='0';
	l0-=fl;
	char pr='2';
	int nw=-1,flg=0;
	while(s.size()){
		char x=*s.rbegin();
		if(x!=pr){
			if(x=='0')
				cnt0--,l0++;
			else {if(nw!=-1&&flg)q.push(-nw);cnt1--,l1++;flg=1;}
			nw=0;
		}
		if(x=='0')cnt0++;
		else cnt1++,flg=1;
		nw++;
		pr=x;
		s.pop_back();
	}
	if(l1==0){
		cout<<a<<endl;
		return ;
	}
	if(c>=b){
		if(cnt0<=cnt1)cout<<cnt0*a+min(cnt1,cnt0+1)*b<<endl;
		else cout<<min(cnt0,cnt1+1)*a+cnt1*b<<endl;
		return ;
	}
	if(cnt1>=cnt0){
		int ans=cnt0*a-min(l0,l1+cnt1-1-cnt0)*c+min(l1+cnt1-1,cnt0+l0+1)*b;
		if(l1+cnt1-cnt0-l0-2>=0)
			ans+=min(l1+cnt1-cnt0-l0-2,fl)*(b-c);
		cout<<ans<<endl;
		return ;
	}
	nw=cnt1;int nc=0;
	int ans=0;
	while(q.size()){
		int x=-q.top();q.pop();
		if(x-1>nw)break;
		nw-=x-1,nc++;
	}
	cout<<(cnt1+1)*a+cnt1*b+nc*(b-c)<<endl;
}
 
signed main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}