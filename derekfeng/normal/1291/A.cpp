#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	int T;
	cin>>T;
	while (T--){
		cin>>n>>s;
		int x=n-1;
		while (x>=0 && (s[x]-'0')%2==0) x--;
		if (x<0){
			puts("-1");continue;
		}
		int o=0;
		for (int i=x;i>=0;i--) o+=(s[i]-'0');
		o%=2;
		if (o==0) cout<<s.substr(0,x+1),puts("");
		else{
			int pos=-1;
			for (int i=0;i<x;i++) if ((s[i]-'0')%2==1) pos=i;
			if (pos==-1) puts("-1");
			else{
				for (int i=0;i<=x;i++) if (pos!=i) cout<<s[i];puts("");
			}
		} 
	}
}