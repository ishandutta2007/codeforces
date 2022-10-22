#include <bits/stdc++.h>
using namespace std;
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
string s;
int T;
int lst[3];
int main(){
	cin>>T;
	while(T--){
		cin>>s;memset(lst,-1,sizeof(lst));;
		int ans=1e9;
		for(int i=0;i<s.size();i++){
			s[i]-='1';
			lst[s[i]]=i;
			int MINN=1e9,MAXN=0,OK=0;
			for(int j=0;j<3;j++){
				if(lst[j]<0) OK=1;
				MINN=min(MINN,lst[j]);
				MAXN=max(MAXN,lst[j]);
			}
			if(OK)continue;
			else ans=min(ans,MAXN-MINN+1);
		}
		if(ans==1e9)puts("0");
		else write(ans),puts("");
	}
}