#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int N=10000,M=100000;
int n,m;
char a[N+5];
string b[M+1];
const int hshmod=19260817;
struct addedge{
	int sz,head[hshmod],nxt[M];
	pair<int,int> data[M];
	void init(){memset(head,-1,sizeof(head));sz=0;}
	void ae(int x,pair<int,int> v){nxt[sz]=head[x];head[x]=sz;data[sz]=v;sz++;} 
	int hav(pair<int,int> v){
		int x=v.X%hshmod;
		for(int i=head[x];~i;i=nxt[i])if(data[i]==v)return i+1;
		return 0;
	}
}tb;
const int hbase1=131,hmod1=998244353,hbase2=13331,hmod2=1000000007;
int pw1[N+1],Hsh1[N+2],pw2[N+1],Hsh2[N+2];
void hsh_init(){
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=n;i++)
		pw1[i]=1ll*pw1[i-1]*hbase1%hmod1,
		pw2[i]=1ll*pw2[i-1]*hbase2%hmod2;
	for(int i=n;i;i--)
		Hsh1[i]=(1ll*Hsh1[i+1]*hbase1+a[i])%hmod1,
		Hsh2[i]=(1ll*Hsh2[i+1]*hbase2+a[i])%hmod2;
}
pair<int,int> hsh(int l,int r){
	pair<int,int> res=mp(((Hsh1[l]-1ll*Hsh1[r+1]*pw1[r-l+1])%hmod1+hmod1)%hmod1,((Hsh2[l]-1ll*Hsh2[r+1]*pw2[r-l+1])%hmod2+hmod2)%hmod2);
//	printf("hsh(%d,%d)=(%d,%d)\n",l,r,res.X,res.Y);
	return res;
}
pair<int,int> mkhsh(string &str){
	int hsh1=0,hsh2=0;
	for(int i=0;i<str.size();i++)
		hsh1=(1ll*hsh1*hbase1+tolower(str[i]))%hmod1,
		hsh2=(1ll*hsh2*hbase2+tolower(str[i]))%hmod2;
	return mp(hsh1,hsh2);
}
bool dp[N+1];
int pa[N+1];
int main(){
	cin>>n>>a+1>>m;
	hsh_init();
	tb.init();
	for(int i=1;i<=m;i++){
		cin>>b[i];
		pair<int,int> h=mkhsh(b[i]);
		tb.ae(h.X%hshmod,h);
//		printf("hsh[%d]=(%d,%d)\n",i,h.X,h.Y);
	}
	dp[0]=true;
	for(int i=1;i<=n;i++){
		for(int j=i-1;~j&&j>=i-1000;j--){
			int fd=tb.hav(hsh(j+1,i));
			if(fd&&dp[j])dp[i]=true,pa[i]=fd;
		}
//		printf("dp[%d]=%d pa[%d]=%s\n",i,dp[i],i,b[pa[i]].c_str());
	}
	vector<int> ans;
	int now=n;
	while(now)ans.pb(pa[now]),now-=b[pa[now]].size();
	for(int i=ans.size()-1;~i;i--)cout<<b[ans[i]]<<" ";
	return 0;
}
/*1
30
ariksihsidlihcdnaehsetahgnisol
10
Kira
hates
is
he
losing
death
childish
L
and
Note
*/
/*2
12
iherehtolleh
5
HI
Ho
there
HeLLo
hello
*/