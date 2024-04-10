#include<bits/stdc++.h>

using namespace std;

const int MX=100005;
int n;
int psb[27],ok,ans;

char s[MX];
int vis[27];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<26;i++)psb[i]=1;
	for(int i=1;i<=n;i++){
		char op[5];
		cin>>op;
		if(op[0]=='.'){
			cin>>s;
			memset(vis,0,sizeof(vis));
			int len=strlen(s);
			for(int j=0;j<len;j++)vis[s[j]-'a']=1;
			for(int j=0;j<26;j++)if(vis[j])psb[j]=0;
			int ts=0;
			for(int j=0;j<26;j++)ts+=psb[j];
			if(ts==1)ok=1;
		}else if(op[0]=='!'){
			ans+=ok;
			cin>>s;
			memset(vis,0,sizeof(vis));
			int len=strlen(s);
			for(int j=0;j<len;j++)vis[s[j]-'a']=1;
			for(int j=0;j<26;j++)if(!vis[j])psb[j]=0;
			int ts=0;
			for(int j=0;j<26;j++)ts+=psb[j];
			if(ts==1)ok=1;
		}else if(op[0]=='?'){
			cin>>s;
			if(!ok){
				psb[s[0]-'a']=0;
				int ts=0;
				for(int j=0;j<26;j++)ts+=psb[j];
				if(ts==1)ok=1;
			}
			else ans+=(psb[s[0]-'a']^1);
		}
	}
	cout<<ans<<endl;
	return 0;
}