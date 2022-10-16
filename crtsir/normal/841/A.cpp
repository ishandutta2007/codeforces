#include<iostream>
#include<algorithm> 
using namespace std;
int a[26],p,y;
int main(){
	string s;
	cin>>y>>p>>s;
	for(int i=0;i<s.size();i++)
		a[s[i]-97]++;
	sort(a,a+26);
	if(p<a[25])
		cout<<"NO";
	else
		cout<<"YES";
}