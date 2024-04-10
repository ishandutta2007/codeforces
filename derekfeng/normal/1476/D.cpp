#include<bits/stdc++.h>
using namespace std;
int T,n;
string s;
int d[300004],f[300004];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;s="$"+s;
		for(int i=0;i<=n;i++)d[i]=f[i]=0;
		for(int i=1;i<=n;i++){
			d[i]=0;
			if(s[i]=='L'){
				d[i]=1;
				if(i>1&&s[i-1]=='R')d[i]=d[i-2]+2;
			}
		}
		for(int i=n-1;i>=0;i--){
			f[i]=0;
			if(s[i+1]=='R'){
				f[i]=1;
				if(i<n-1&&s[i+2]=='L')f[i]=f[i+2]+2;
			}
		}
//		for(int i=0;i<=n;i++)cout<<f[i]<<" ";
//		return 0;
		for(int i=0;i<=n;i++)cout<<d[i]+f[i]+1<<" ";
		puts("");
	}
}