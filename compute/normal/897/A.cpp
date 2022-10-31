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
int main()
{
		int n,m;
			cin>>n>>m;
				string s;
					cin>>s;
						char c1,c2;
							while(m--)
									{
											int l,r;
											cin>>l>>r;
											cin>>c1>>c2;
											dbg(c1,c2);
											for(int i=l-1;i<r;i++)
											{
														if(s[i]==c1) s[i]=c2;
													}
										}
								cout<<s<<endl;
}