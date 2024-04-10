#include<bits/stdc++.h>
using namespace std;
int T;
string s;
bool ok[104],ko[104];
int main(){
	cin>>T;
	while(T--){
		cin>>s;int n=s.size();s="^"+s;
		ok[0]=ok[1]=1;
		for(int i=2;i<=n;i++)ok[i]=ok[i-1]&(s[i]!=s[i-1]||s[i]!='1');
		ko[n+1]=ko[n]=1;
		for(int i=n-1;i;i--)ko[i]=ko[i+1]&(s[i]!=s[i+1]||s[i]!='0');
		bool tmp=0;
		for(int i=0;i<=n;i++)if(ok[i]&&ko[i+1]){
			tmp=1;break;
		}
		puts(tmp?"YES":"NO");
	}
}