// Problem: CF1553D Backspace
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1553D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int T;char s[N],t[N];
signed main(){
	cin>>T;
	while(T--){
		cin>>s+1;int n=strlen(s+1);
		cin>>t+1;int m=strlen(t+1);
		if(n<m){
			puts("NO");
			continue;
		}
		bool ans=false;int pos=((n-m)&1)+1;
		for(int i=1;i<=m;i++){
			while(t[i]!=s[pos]){
				pos+=2;
				if(pos>n+1)
					goto nxt1;
			}
			pos++;
			if(pos>n+1)goto nxt1;
		}
		ans=1;
		nxt1:;
		puts(ans?"YES":"NO");
	}
}