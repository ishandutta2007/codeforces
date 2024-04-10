#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
int arr[105];
int main()
{
	int n;
	cin>>n;
	int ans=0;
	bool inf=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(!i) continue;
		if((arr[i]==arr[i-1]||(arr[i]+arr[i-1]==5))) {inf=1;}
		else{
			if(i>1&&arr[i]==2&&arr[i-1]==1&&arr[i-2]==3) ans+=2;
			else if(arr[i]+arr[i-1]==3) ans+=3;
			else if(arr[i]+arr[i-1]==4) ans+=4;
		}
	}
	if(inf) cout<<"Infinite"<<endl;
	else {
		cout<<"Finite"<<endl;
		cout<<ans<<endl;
	}
}