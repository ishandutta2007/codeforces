#include<bits/stdc++.h>

using namespace std;

const int MX=5005;
char s[MX];

int main(){
	ios::sync_with_stdio(false);
	cin>>(s+1);
	int n=strlen(s+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int mx=0,mn=0;
		for(int j=i;j<=n;j++){
			if(s[j]=='(')++mx,++mn;
			else if(s[j]==')'){
				--mx,--mn;
				while(mn<0)mn+=2;
			}else{
				++mx,--mn;
				while(mn<0)mn+=2;
			}
			if(mx<mn)break;
			if((j-i)&1){
				if(mx>=mn&&mn==0)++ans;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}