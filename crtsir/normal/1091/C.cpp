#include<bits/stdc++.h>
using namespace std;
vector<long long>x;
int main(){
	long long n;
	cin>>n;
	for(int i=sqrt(n);i>0;i--)
	{
		if(n%i)continue;
		x.push_back(n/i*(n-i+2)/2);
		if(i!=sqrt(n))x.push_back(i*(n-n/i+2)/2);
	}
	sort(x.begin(),x.end());
	for(int i=0;i<x.size();i++)cout<<x[i]<<' ';
}