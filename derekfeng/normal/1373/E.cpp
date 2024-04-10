#include<bits/stdc++.h>
using namespace std;
int T,n,K;
string ans;
string MAKE(int x){
	string ret="";
	for(int i=0;i<x/9;i++)ret+="9";
	if(x%9>0)ret=(char)(x%9+'0')+ret;
	return ret;
}
string MMake(int x){
//	cout<<x<<"\n";
	if(x%9>0){
		if(x<9){
			string ret="";
			ret+=(char)(x+'0');
			return ret;
		} 
		int num=9+x%9;x-=9;
		return (char)(num-8+'0')+MAKE(x/9*9)+(char)(8+'0');
	}
	if(x==0)return"";
	return "1"+MAKE(x-9)+"8";
}
void add(string S){
	if(ans.size()>S.size())ans=S;
	if(ans.size()<S.size())return;
	for(int i=0;i<S.size();i++)if(S[i]!=ans[i]){
		if(ans[i]>S[i])ans=S;
		else return;
	}
}
void solve(){
	ans=MAKE(3000);
//	cout<<ans.size()<<"\n";
	cin>>n>>K;
	for(int i=0;i<=9;i++)if(i+K<10){
		int num=K*(K+1)/2+i*(K+1);
		if(num>n)continue;
		if((n-num)%(K+1)>0)continue;
		string ret=MAKE((n-num)/(K+1));
		ret+=(char)(i+'0');
		add(ret);
	}
//	cout<<ans<<"\n";
	for(int i=0;i<=9;i++)if(i+K>9)
		for(int j=0;j<=20;j++){
			int N9=10-i,N0=K+1-N9;
		//	cout<<i<<" "<<N9<<" "<<N0<<"A\n";
			int num=0;
			for(int k=i,l=0;l<=K;k++,l++,k%=10)num+=k;
		//	cout<<i<<" "<<N9<<" "<<N0<<"B\n";
			num+=N9*j*9+N0;
			if(num>n || (n-num)%(K+1)>0)continue;
			string ret=MMake((n-num)/(K+1));
		//	cout<<((n-num)/(K+1))<<"\n";
		//	cout<<i<<" "<<j<<" "<<num<<" "<<ret<<"\n";
			for(int k=0;k<j;k++)ret+="9";
			ret+=(char)(i+'0');
		//	cout<<i<<" "<<j<<" "<<num<<" "<<ret<<"\n";
			add(ret);
		//	cout<<i<<" "<<N9<<" "<<N0<<"C\n";
		}
	if(ans.size()>300)puts("-1");
	else cout<<ans<<"\n";
}
int main(){
	cin>>T;
	while(T--)solve();
}