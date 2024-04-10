#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t;string s;
	scanf("%d%d",&n,&t);
	cin>>s;
	for(int i=0;i<t;i++)
		for(int j=1;j<n;j++)
			if(s[j-1]=='B'&&s[j]=='G')
				swap(s[j-1],s[j]),j++;
	cout<<s;
}