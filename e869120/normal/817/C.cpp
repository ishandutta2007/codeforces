#include<bits/stdc++.h>
using namespace std;
long long n,s;
bool solve(long long u){
	if(u<0)return false;
	string S=to_string(u);
	for(int i=0;i<S.size();i++)u-=(S[i]-'0');
	if(u>=s)return true;
	return false;
}
int main(){
	cin>>n>>s;
	long long L=0,R=(1LL<<60),M;
	while(true){
		M=(L+R)/2;
		bool p1=solve(M-1),p2=solve(M);
		if(p1==false && p2==true){cout<<max(0LL,n-M+1)<<endl;break;}
		if(p1==true)R=M;else L=M;
	}
	return 0;
}