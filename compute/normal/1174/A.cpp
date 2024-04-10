#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
int arr[2505];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n*2;i++)
		cin>>arr[i];
	sort(arr,arr+2*n);
	int fi=0,se=0;
	for(int i=0;i<n;i++) fi+=arr[i];
	for(int i=n;i<2*n;i++) se+=arr[i];
	if(fi==se) cout<<-1<<endl;
	else{
		for(int i=0;i<2*n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
}