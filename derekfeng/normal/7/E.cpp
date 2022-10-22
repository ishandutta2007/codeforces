#include <bits/stdc++.h>	
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
string epr[103],names[103];
map <string,int> mp;
void reads(int x){
	char ch=getchar();
	for (;ch==' '||ch=='#';ch=getchar());
	for (;ch!=' ';ch=getchar());
	for (;ch==' ';ch=getchar());
	for (;ch!=' ';names[x]+=ch,ch=getchar());
	mp[names[x]]=x;
	for (;ch==' ';ch=getchar());
	for (;ch!='\n';){
		if (ch!=' ')epr[x]+=ch;
		ch=getchar();
	}
}
string HERMITPURPLE,s;
int n,dp[103];
int calc[103][103];
void outputno(){
	puts("Suspicious");exit(0);
}
void init(){
	char ch=getchar(); 
	for (;ch!='\n';){
		if (ch!=' ')epr[n+1]+=ch;
		ch=getchar();
	}
}
int go(int x,int l,int r);
int solve(int x){
	if (x==0) return 3;
	if (dp[x]) return dp[x];
	stack<int>lft;
	for (int i=0;i<epr[x].size();i++){
		if (epr[x][i]==')') calc[x][i]=lft.top(),calc[x][lft.top()]=i,lft.pop();
		if (epr[x][i]=='(') lft.push(i);
	}
	return dp[x]=go(x,0,epr[x].size()-1);
}
int go(int x,int l,int r){
	if (calc[x][l]==r){
		if (l==r-1) return 1;
		else{
			go(x,l+1,r-1);
			return 3;
		}
	}
	bool oneint=1;
	for (int i=l;i<=r;i++) if (epr[x][i]=='+' || epr[x][i]=='-' || epr[x][i]=='/' || epr[x][i]=='*' || epr[x][i]=='(') oneint=0;
	if (oneint) return solve(mp[epr[x].substr(l,r-l+1)]);
	bool pot=0;
	for (int i=l;i<=r;){
		if (epr[x][i]=='(') i=calc[x][i]+1;
		else{
			if (epr[x][i]=='+' || epr[x][i]=='-'){
				pot=1;break;
			}
			i++;
		}
	}
	vector<int>copyr,ans;
	if (!pot){
		copyr.push_back(l-1);
		for (int i=l;i<=r;){
			if (epr[x][i]=='(') i=calc[x][i]+1;
			else{
				if (epr[x][i]=='/' || epr[x][i]=='*') copyr.push_back(i);
				i++;
			}
		}
		copyr.push_back(r+1);
		for (int i=1;i<copyr.size();i++) ans.push_back(go(x,copyr[i-1]+1,copyr[i]-1));
		if (ans[0]==1) outputno();
		for (int i=1;i<ans.size();i++){
			if (epr[x][copyr[i]]=='/' && ans[i]!=3) outputno();
			if (epr[x][copyr[i]]=='*' && ans[i]==1) outputno();
		}
		return 2;
	}else{
		copyr.push_back(l-1);
		for (int i=l;i<=r;){
			if (epr[x][i]=='(') i=calc[x][i]+1;
			else{
				if (epr[x][i]=='+' || epr[x][i]=='-') copyr.push_back(i);
				i++;
			}
		}
		copyr.push_back(r+1);
		for (int i=1;i<copyr.size();i++) ans.push_back(go(x,copyr[i-1]+1,copyr[i]-1));
		for (int i=1;i<ans.size();i++)
			if (epr[x][copyr[i]]=='-' && ans[i]==1) outputno();
		return 1;
	}
}
int main(){
	memset (calc,-1,sizeof(calc));
	read(n);
	for (int i=1;i<=n;i++)
		reads(i);
	init();
	solve(n+1);
	puts("OK");
}