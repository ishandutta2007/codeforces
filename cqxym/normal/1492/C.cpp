#include<iostream>
using namespace std;
#define R register int
int f[200000],g[200000];
inline int Find1(string&s,int l,char c){
	while(true){
		if(s[l]==c){
			return l;
		}
		l++;
	}
}
inline int Find2(string&s,int r,char c){
	while(true){
		if(s[r]==c){
			return r;
		}
		r--;
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	f[0]=Find1(s,0,t[0]);
	for(R i=1;i!=m;i++){
		f[i]=Find1(s,f[i-1]+1,t[i]);
	}
	g[m-1]=Find2(s,n-1,t[m-1]);
	for(R i=m-2;i!=-1;i--){
		g[i]=Find2(s,g[i+1]-1,t[i]);
	}
	int ans=0;
	for(R i=1;i!=m;i++){
		ans=max(ans,g[i]-f[i-1]);
	}
	cout<<ans;
	return 0;
}