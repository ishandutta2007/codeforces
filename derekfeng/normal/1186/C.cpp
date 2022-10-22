#include <bits/stdc++.h>
using namespace std;
string a,b;
int gua[1000004],num=0,ans=0;
int main(){
	cin>>a>>b;
	for (int i=0;i<a.size();i++){
		if (a[i]=='0') gua[i+1]=gua[i];
		else gua[i+1]=gua[i]+1;
	}
	for (int i=0;i<b.size();i++) if (b[i]=='1') num++;
	for (int i=1;i<=a.size();i++)if(i>=b.size()){
		int num1=gua[i]-gua[i-b.size()];
		if ((num1+num)%2==0) ans++;
	}
	cout<<ans;
}