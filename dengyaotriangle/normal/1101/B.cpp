#include<bits/stdc++.h>

using namespace std;

const int maxn=500005;

int n;
char x[maxn];

int main(){
	cin>>x;
	n=strlen(x);
	int lbp=-1,rbp=-1;
	for(int i=0;i<n;i++){
		if(x[i]=='['){
			lbp=i;
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(x[i]==']'){
			rbp=i;
			break;
		}
	}
	if(rbp<lbp||lbp==-1||rbp==-1){
		cout<<-1;
		return 0;
	}
	int cnt=0,lm,rm;
	for(int i=lbp;i<=rbp;i++){
		if(x[i]==':') cnt++;
	}
	for(int i=lbp;i<=rbp;i++){
		if(x[i]==':'){
			lm=i;
			break;
		}
	}
	for(int i=rbp;i>=lbp;i--){
		if(x[i]==':'){
			rm=i;
			break;
		}
	}
	if(cnt<2){
		cout<<-1;
		return 0;
	}
	int ans=0;
	for(int i=lm;i<=rm;i++){
		if(x[i]=='|'){
			ans++;
		}
	}
	cout<<ans+4;
	return 0;
}