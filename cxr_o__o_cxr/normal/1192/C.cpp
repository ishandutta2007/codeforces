#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int mod=998244353;
int n,ans,g[64][64][64],a[64][64],cc[2][2][2]={24,12,12,4,12,6,4,1};
vector<string>s[16];
string ss;
inline int get(char c){
	if('a'<=c&&c<='z')return c-'a'+1;
	if('A'<=c&&c<='Z')return c-'A'+27;
	return c-'0'+53;
}
inline void solve(int l){
	memset(g,0,sizeof(g));
	memset(a,0,sizeof(a));
	sort(s[l].begin(),s[l].end());
	for(int i=0,sz=s[l].size();i<sz;i++)
		if(!i||s[l][i]!=s[l][i-1])a[get(s[l][i].front())][get(s[l][i].back())]++;
	for(int i=1;i<=62;i++)
		for(int u=1;u<=62;u++)if(a[i][u])
			for(int v=u;v<=62;v++)if(a[i][v])
				for(int w=v;w<=62;w++)if(a[i][w])
					g[u][v][w]=((ll)a[i][u]*a[i][v]%mod*a[i][w]+g[u][v][w])%mod;
	for(int c1=1;c1<=62;c1++)
		for(int c2=c1;c2<=62;c2++)
			for(int c3=c2;c3<=62;c3++)if(g[c1][c2][c3])
				for(int c4=c3;c4<=62;c4++)
					ans=((ll)cc[c1==c2][c2==c3][c3==c4]*g[c1][c2][c3]%mod*g[c1][c2][c4]%mod*g[c1][c3][c4]%mod*g[c2][c3][c4]+ans)%mod;
}
int main(){
	n=read();
	for(int i=1,len;i<=n;i++){
		cin>>ss;
		len=ss.size();
		s[len].push_back(ss);
		reverse(ss.begin(),ss.end());
		s[len].push_back(ss);
	} 
	for(int i=3;i<=10;i++)if(!s[i].empty())solve(i);
	cout<<ans;
	return (0-0);
}