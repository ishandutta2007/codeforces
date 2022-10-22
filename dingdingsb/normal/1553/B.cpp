// Problem: Reverse String
// Contest: Codeforces
// URL: https://m1.codeforces.ml/contest/1553/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1100;
int T;char s[N],t[N];
signed main(){
	cin>>T;
	while(T--){
		cin>>s+1;int n=strlen(s+1);
		cin>>t+1;int m=strlen(t+1);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n&&j-i+1<=m;j++){
				if(s[j]!=t[j-i+1])break;
				if(j-1<m-(j-i+1))continue;
				for(int k=j-1;j-k<=m-(j-i+1);k--)
					if(s[k]!=t[j-k+(j-i+1)])
						goto nxt;
				puts("YES");
				goto loop;
				nxt:;
			}
		}
		puts("NO");
		loop:;
		
	}
}