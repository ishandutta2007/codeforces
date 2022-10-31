#include<bits/stdc++.h>
using namespace std;
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
vector<int> A,B,C,D;
int main()
{
	int n;
	string s,t;
	cin>>n>>s>>t;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0'&&t[i]=='0') A.push_back(i+1);
		else if(s[i]=='1'&&t[i]=='0') B.push_back(i+1);
		else if(s[i]=='0'&&t[i]=='1') C.push_back(i+1);
		else D.push_back(i+1);
	}
	int ansb=-1,ansc=-1,ansa,ansd;
	for(int a=0;a<=A.size();a++)
	{
		for(int c=0;c<=C.size();c++)
		{
			int cur=A.size()-2*a+c;
			if(cur<0||cur>B.size()) continue;
			else{
				ansa=A.size()-a;ansb=B.size()-cur;
				ansc=c;
				ansd=n/2-(ansa+ansb+ansc);
				if(ansd<0||ansd>D.size()) ansb=-1;
			}
			if(ansb!=-1) break;
		}
		if(ansb!=-1) break; 
	}
	dbg(ansa);dbg(ansb);dbg(ansc);dbg(ansd);
	if(ansb<0||ansd<0||ansd>D.size()) cout<<-1<<endl;
	else {
		for(int i=0;i<ansa;i++)
			cout<<A[i]<<" ";
		for(int i=0;i<ansb;i++)
			cout<<B[i]<<" ";
		for(int i=0;i<ansc;i++)
			cout<<C[i]<<" ";
		for(int i=0;i<ansd;i++)
			cout<<D[i]<<" ";
		cout<<endl;
	}

}