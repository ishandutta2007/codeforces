#include<bits/stdc++.h>
using namespace std;
int t,n,m;
string s;
int lst[1003],nxt[1003];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>s;
		for(int i=0;i<n;i++){
			lst[i]=-1;
			if(i>0)lst[i]=lst[i-1];
			if(s[i]=='1')lst[i]=i;
		}
		for(int i=n-1;i>=0;i--){
			nxt[i]=-1;
			if(i<n-1)nxt[i]=nxt[i+1];
			if(s[i]=='1')nxt[i]=i;
		}
		for(int i=0;i<n;i++){
			if(s[i]=='0'&&((lst[i]==-1&&nxt[i]==-1)||(lst[i]>=0&&nxt[i]>=0&&i-lst[i]==nxt[i]-i)))putchar('0');
			else if(s[i]=='1'||(lst[i]!=-1&&i-lst[i]<=m)||(nxt[i]!=-1&&nxt[i]-i<=m))putchar('1');
			else putchar('0');
		}
		puts("");
	}
}