//starusc
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mk make_pair
#define pb push_back
const int N=2e5+4,mod=1e9+713,B=317;
map<pair<int,int>,vector<int> >f[N];
int n,ans,q[N],pw[N],hsh[N];
char s[N];
inline int Hash(int l,int r){
	return (hsh[r]-(ll)hsh[l-1]*pw[r-l+1]%mod+mod)%mod;
}
int main(){
	scanf("%d%s",&n,s+1);
	pw[0]=1;
	for(int i=1;i<=n;i++){
		hsh[i]=((ll)hsh[i-1]*B+s[i])%mod;
		pw[i]=(ll)pw[i-1]*B%mod;
	}
	for(int i=1;i<=n;i++)f[1][mk(s[i],1)].pb(i);
	for(int i=1,len,m;i<=n;i++)if(!f[i].empty()){
		ans=i;
		for(auto it:f[i]){
			len=it.first.second;
			vector<int> tmp=it.second;
			m=tmp.size()-1;
			for(int j=0;j<m;j++)
				q[j]=Hash(tmp[j]+len,tmp[j+1]-1);
			for(int l=0,r=1;l<m;l=r,r++){
				for(;r<m&&q[r-1]==q[r];r++);
				f[i+r-l][mk(Hash(tmp[l],tmp[r]+len-1),tmp[r]-tmp[l]+len)].pb(tmp[l]);// 
			}
		}
	}
	cout<<ans;
	return (0-0);
}