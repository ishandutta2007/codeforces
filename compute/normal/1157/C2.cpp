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
const int maxn=2e5+7;
int arr[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	string ans="";
	int l=0,r=n-1;
	int cur=-1;
	while(l<=r)
	{
		if(cur>=arr[l]&&cur>=arr[r]) break;
		if(cur<arr[l]&&cur<arr[r])
		{
			if(arr[l]<arr[r])
			{
				cur=arr[l];
				ans+='L';
				l++;
			}
			else if(arr[r]<arr[l]){
				cur=arr[r];
				ans+='R';
				r--;
			}
			else{
				if(l==r)
				{
					cur=arr[l];
					l++;
					ans+='L';
				}
				else{
					int cnt=0,piv=cur;
					for(int i=l;i<=r;i++)
					{
						if(piv<arr[i]) cnt++,piv=arr[i];
						else break;
					}
					int cnt2=0;piv=cur;
					for(int i=r;i>=l;i--)
					{
						if(piv<arr[i]) cnt2++,piv=arr[i];
						else break;
					}
					dbg(cnt,cnt2);
					if(cnt>cnt2)
						for(int i=0;i<cnt;i++) ans+='L';
					else for(int i=0;i<cnt2;i++) ans+='R';
					break;
				}
			}
		}
		else if(cur<arr[l])
		{
			cur=arr[l];
			ans+='L';
			l++;
		}
		else{
			cur=arr[r];
			ans+='R';
			r--;
		}
	}
	cout<<ans.length()<<endl;
	cout<<ans<<endl;
}