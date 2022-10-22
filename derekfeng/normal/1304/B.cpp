#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,has;
string s[103];
map <string,int> mp;
string ans1,ans2;
string go(string s){
	string res;
	for (int i=m-1;i>=0;i--) res+=s[i];
	return res;
}
int main(){
	read(n),read(m);
	for (int i=1;i<=n;i++) cin>>s[i],mp[s[i]]++;
	for (int i=1;i<=n;i++){
		if (mp[s[i]]==0) continue;
		string nxt=go(s[i]);
		if (s[i]==nxt){
			while (mp[s[i]]>=2) ans1=s[i]+ans1,ans2=ans2+s[i],mp[s[i]]-=2;
		}else{
			while (mp[s[i]]>0 && mp[nxt]>0) ans1=s[i]+ans1,ans2=ans2+nxt,mp[nxt]--,mp[s[i]]--;
		}
		if (mp[s[i]]==0 || has || nxt!=s[i]) continue;
		has=1;
		ans1+=s[i];
		mp[s[i]]--;
	}
	cout<<ans1.size()+ans2.size()<<"\n";
	cout<<ans1+ans2;
}