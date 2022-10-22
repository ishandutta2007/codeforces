#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int n,a[26];
int num1;
string s1,s2;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],num1+=a[i]%2;
	int ans=a[0]; 
	for(int i=1;i<n;i++)ans=gcd(ans,a[i]);
	if(num1>1){
		puts("0");
		for(int i=0;i<n;i++)for(int j=0;j<a[i];j++)putchar(i+'a');
		return 0;
	}
	printf("%d\n",ans);
	if(num1<1){
		ans/=2;
		for(int i=0;i<n;i++)a[i]/=ans;
		for(int i=0;i<n;i++)
			for(int j=0;j<a[i]/2;j++)
				s1+=(char)(i+'a');
		s2=s1,reverse(s2.begin(),s2.end());
		s1+=s2;
		for(int i=0;i<ans;i++)cout<<s1;
		return 0;
	}
	for(int i=0;i<n;i++)a[i]/=ans;
	for(int i=0;i<n;i++)if(a[i]%2==0)
		for(int j=0;j<a[i]/2;j++)
			s1+=(char)(i+'a');
	s2=s1,reverse(s2.begin(),s2.end());
	for(int i=0;i<n;i++)if(a[i]%2==1)
		for(int j=0;j<a[i];j++)s1+=(char)(i+'a');
	s1+=s2;
	for(int i=0;i<ans;i++)cout<<s1;
}