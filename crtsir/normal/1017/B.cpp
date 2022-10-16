#include<bits/stdc++.h>
using namespace std;
unsigned long long n,num[2][2];
string a,b;
int main(){
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
		num[a[i]-'0'][b[i]-'0']++;
	cout<<num[1][0]*(num[0][1]+num[0][0])+num[0][0]*(num[1][1]);
}