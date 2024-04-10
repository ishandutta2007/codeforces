#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MP(x,y) make_pair(x,y)  
template <class T1, class T2>inline void getmax(T1 &a, T2 b) { if (b>a)a = b; }  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) { if (b<a)a = b; }
int read()
{
	int v = 0, f = 0;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}

int main()
{	
	//freopen("in.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	int a[n+1],b[m+1];
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin>>b[i];
	}
	int ans = 0 ;
	for(int i = 0; i<n; i++){
		int l = 0, r = m-1;
		while(r-l>1){
			int mid = (r+l)>>1;
			if(b[mid] >= a[i]){
				r = mid;
			}
			else{

				l=mid;
			}
		}
		int cnt = min(abs(a[i]-b[l]),abs(a[i]-b[r]));
		ans = max(ans, cnt);
	}
	cout<<ans;
	return 0;
}