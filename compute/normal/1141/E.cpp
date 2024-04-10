#include<bits/stdc++.h>
using namespace std;
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
const int maxn=2e5+7;
long long arr[maxn];
int main()
{
	long long hp;
	int round;
	cin>>hp>>round;
	long long loop=0;
	long long mi=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=round;i++)
	{
		cin>>arr[i];
		arr[i]+=arr[i-1];
		mi=min(arr[i],mi);
	}
	long long ans=0;
	if(hp+mi>0&&arr[round]>=0) cout<<-1<<endl;
	else{
		if(hp+mi<=0)
		{
			for(int i=1;i<=round;i++)
			{
				if(arr[i]+hp<=0)
				{
					ans=i;break;
				}
			}
		}
		else{
			ans+=ceil((double)(hp+mi)/(-arr[round]))*round;
			hp-=ans/round*(-arr[round]);
			for(int i=1;i<=round;i++)
			{
				if(arr[i]+hp<=0)
				{
					ans+=i;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}

}