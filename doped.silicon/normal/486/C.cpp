#include <iostream>
using namespace std;

int main() {
	int n,p,b;
	string s;
	cin>>n>>p;
	int ans=0;
	cin>>s;
	
		int a=n/2;
		b=1;
		for(int i=a;i>0;i--)
		{
		     if(s[i-1]==s[n-i]){
		     a--;}
		     else 
		     break;
		}
		for(int i=1;i<=a;i++)
		{
		     if(s[i-1]==s[n-i]){
		     //cout<<"fgsf";
		     b++;}
		     else 
		     break;
		}
		if(a!=0)
		ans=min(min(abs(p-a),abs(n-a-p+1)),min(abs(p-b),abs(n-b+1-p)));
		
		for(int i=a;i>0;i--)
		{
			ans+=min(abs(s[i-1]-s[n-i]),min(abs(s[i-1]-97+123-s[n-i]),abs(s[n-i]-97+123-s[i-1])));
			//cout<<ans<<"\n";
		}
	//cout<<ans<<" "<<a<<" "<<b<<"\n";
	if(a!=0)
	cout<<ans+a-b;
	else
	cout<<"0";
	return 0;
}