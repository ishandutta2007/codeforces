#include<bits/stdc++.h>
//const int N=;
using namespace std;

void solve(){
	int n;cin>>n;
	string a,b;cin>>a>>b;
	int ans1=0,fl1=0,ans2=0,fl2=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==b[i])ans1++,fl1+=a[i]-'0';
		else          ans2++,fl2+=a[i]-'0';
	}
	int res=1e9;
	if(fl1*2-1==ans1)res=min(res,ans1);
	if(fl2*2==ans2)res=min(res,ans2);
	if(res==1e9)cout<<-1<<'\n';
	else cout<<res<<'\n';
}

int main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}