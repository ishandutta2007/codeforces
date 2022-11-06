#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Trie{
	int c[26];
}t[1000002];
char s[1002];
int tot,n;
void insert(int p,int i){
	int j,k;
	for(j=i;j<=n;++j){
		k=s[j]-'a';
		if(!t[p].c[k])t[p].c[k]=++tot;
		p=t[p].c[k];
	}
}
int ans;
string Ans;
string S[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n",
"o","p","q","r","s","t","u,","v","w","x","y","z"};
void DFS(int p,string s,int len){
	int i;
	string s1;
	if(len+1>ans)return;
	for(i=0;i<26;++i){
		if(!t[p].c[i]){
			s1=s+S[i];
			if(len+1<ans){
				Ans=s1;
				ans=len+1;
			}
			else if(len+1==ans&&s1<Ans){
				s1=Ans;
			}
		}
		else DFS(t[p].c[i],s+S[i],len+1);
	}
}
int main(){
	int T,i,j,k;
	scanf("%d",&T);
	while(T--){
		for(i=0;i<=tot;++i)for(j=0;j<26;++j)t[i].c[j]=0;
		tot=0;ans=1002;
		scanf("%d%s",&n,s+1);
		for(i=1;i<=n;++i)insert(0,i);
		DFS(0,"",0);
		cout<<Ans<<endl;
	}
	return 0;
}