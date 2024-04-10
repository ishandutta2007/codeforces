#include<bits/stdc++.h>
using namespace std;
void reads(string &s){
	register char ch=getchar();s="";
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
int T,pos[1000004];string s;
void solve(){
	reads(s);
	int n=s.size(),cur=0,maxn=0;long long ans=0;
	for(int i=0;i<=n+2;i++)pos[i]=1e9;
	for(int i=0;i<n;i++){
		if(s[i]=='-')cur++;
		else cur--;
		maxn=max(maxn,cur);
	}
	cur=0;
	for(int i=0;i<n;i++){
		if(s[i]=='-')cur++;
		else cur--;
		if(cur>0)pos[cur]=min(pos[cur],i);
	}
	for(int i=n;i>=1;i--)pos[i]=min(pos[i+1],pos[i]);
	for(int i=0;i<maxn;i++)
		ans+=pos[i+1]+1;
	cout<<ans+n<<"\n";
}
int main(){
	cin>>T;
	while(T--)
		solve();
}