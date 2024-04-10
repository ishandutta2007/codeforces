#include<iostream>
using namespace std;
string s[100001];
int x[100001];
int main(){
	int n,js=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
	{
		int f=1;
		for(int j=i-1;j>-1;j--)
			if(s[i]==s[j])
				{
					x[i]=x[j]+1;
					cout<<s[i]<<x[i]<<endl;
					f=0;
					break;
				}
		if(f==1)cout<<"OK"<<endl;
	}
}