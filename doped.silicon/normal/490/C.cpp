#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	string s;
	cin>>s;
	long long int x,y;
	cin>>x>>y;
	long long int c[s.length()];
	long long int a[s.length()];
	long long int b[s.length()];
	for(long long int i=0;i<s.length();i++)
	{
		c[i]=s[i]-'0';
	}
	bool f=true;
	long long int i;
	a[0]=c[0]%x;
	if(a[0]==0){
                        f=false;
		i=0;
			
		}
	for(i=0;i<s.length()&&f;i++)
	{
		if(i!=0)
		a[i]=(a[i-1]*10+c[i])%x;
		if(a[i]==0){
                        f=false;
		i--;
	//	cout<<"Zfdsad";
		}
	}
	if(f==false){
		//cout<<"sdfa";
	long long int p=10;
	p=p%y;
	b[s.length()-1]=c[s.length()-1]%y;
	for(int k=s.length()-2;k>=i+1;k--)
	{
		b[k]=((c[k]%y)*p+b[k+1])%y;
		p=p*10%y;
	}
	//cout<<i;
	f=true;
	if(i!=s.length()-1&&b[i+1]==0&&c[i+1]!=0){
	cout<<"YES\n";
	cout<<s.substr(0,i+1)<<endl;
	cout<<s.substr(i+1,s.length()-i-1)<<endl;
	}
	else
	{
		i++;
		for(;i<s.length()-1&&f;i++)
		{
			a[i]=(a[i-1]*10+c[i])%x;
			//cout<<i<<"fads"<<a[i]<<"\n";
			if(a[i]==0&&b[i+1]==0&&c[i+1]!=0)
			{
				f=false;
				cout<<"YES\n";
				cout<<s.substr(0,i+1)<<endl;
             	                        cout<<s.substr(i+1,s.length()-i-1)<<endl;
			}
		}
		if(f){
		cout<<"NO\n";
		}
	}}
	else{
		cout<<"NO\n";
	}
	return 0;
}