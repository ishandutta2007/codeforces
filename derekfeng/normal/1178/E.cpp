#include<bits/stdc++.h>
using namespace std;
int num[3];
string s,ans;
void dfs(int l,int r){
	if(r<l)return;
	if(r-l<3){
		putchar(s[l]);
		return;
	}
	num[0]=num[1]=num[2]=0;
	for(int i=l;i<l+2;i++)num[s[i]-'a']++;
	for(int i=r-1;i<=r;i++)num[s[i]-'a']++;
	if(num[0]>1)putchar('a'),ans+="a";
	else if(num[1]>1)putchar('b'),ans+="b";
	else putchar('c'),ans+="c";
	dfs(l+2,r-2);
}
int main(){
	cin>>s;
	dfs(0,s.size()-1);
	reverse(ans.begin(),ans.end());
	cout<<ans;
}