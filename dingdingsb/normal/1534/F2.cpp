#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
int n,m,pos,ans;
vector<vector<char>>s;
vector<vector<int>>L,R;
vector<int>a,f;
void dfs(int x,int y,int k,vector<vector<int>>&arr){
	if(arr[x][y]!=-1)return;arr[x][y]=k;
	if(x<n)dfs(x+1,y,k,arr);
	if(x>1&&s[x-1][y]=='#')dfs(x-1,y,k,arr);
	if(y>1&&s[x][y-1]=='#')dfs(x,y-1,k,arr);
	if(y<m&&s[x][y+1]=='#')dfs(x,y+1,k,arr);
}
signed main(){
	read(n,m);
	s=vector<vector<char>>(n+3,vector<char>(m+3));
	L=vector<vector<int>>(n+3,vector<int>(m+3,-1));
	R=vector<vector<int>>(n+3,vector<int>(m+3,-1));
	a=vector<int>(m+2);
	f=vector<int>(m+3,m+2);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			s[i][j]=getchar();
			while(s[i][j]!='.'&&s[i][j]!='#')
				s[i][j]=getchar();
		}
	for(int i=1;i<=m;i++)read(a[i]);
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			if(s[i][j]=='#')
				dfs(i,j,j,L);
	for(int j=m;j;j--)
		for(int i=1;i<=n;i++)
			if(s[i][j]=='#')
				dfs(i,j,j,R);
	for(int j=1;j<=m;j++)if(a[j])
		for(int i=n;i>=1;i--)if(s[i][j]=='#'){
			a[j]--;
			if(a[j]==0){
				chkmn(f[L[i][j]],R[i][j]+1);
				break;
			}
		}
	for(int i=m+1;i;i--)chkmn(f[i],f[i+1]);
	int pos=1,ans=0;
	while(pos<m+2)
		pos=f[pos],ans++;
	write(ans-1); 
}