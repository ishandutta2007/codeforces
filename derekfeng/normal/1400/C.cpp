#include<bits/stdc++.h>
using namespace std;
int T,n,X;
string s;
char ans[100004],w[100004]; 
int main(){ 
	cin>>T;
	while(T--){
		cin>>s>>X;n=s.size();s="*"+s;
		for(int i=1;i<=n;i++)ans[i]='1',w[i]='0';
		for(int i=1;i<=n;i++)
			if(s[i]=='0'){
				if(i>X)ans[i-X]='0';
				if(i+X<=n)ans[i+X]='0';
			}
		for(int i=1;i<=n;i++){
			if(i>X&&ans[i-X]=='1')w[i]='1';
			if(i+X<=n&&ans[i+X]=='1')w[i]='1';
		}
		bool ok=1;
		for(int i=1;i<=n&&ok;i++)if(w[i]!=s[i])ok=0;
		if(!ok)puts("-1");
		else{
			for(int i=1;i<=n;i++)putchar(ans[i]);puts("");
		}
	}
}