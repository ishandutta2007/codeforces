#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	int a[s.size()/2+1];
	for(int i=0;i<s.size();i+=2)
		a[i/2]=s[i]-'0';
	sort(a,a+s.size()/2+1);
	cout<<a[0];
	for(int i=1;i<s.size()/2+1;i++)
		cout<<"+"<<a[i];
}