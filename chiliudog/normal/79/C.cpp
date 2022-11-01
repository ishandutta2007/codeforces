#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=100005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
char s[maxn],s1[maxn];
int pre[maxn],last[maxn],n;
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
inline void solve(){
	int j=0;int m=strlen(s1+1);
	rep(i,2,m){
		while(j&&s1[i]!=s1[j+1])j=last[j];
		if(s1[i]==s1[j+1])j++;last[i]=j;
	}j=0;
	rep(i,1,n){
		while(j&&s[i]!=s1[j+1])j=last[j];
		if(s[i]==s1[j+1])j++;
		if(j==m){
			pre[i]=min(pre[i],m-1);j=last[j];
		}
	}
}
int f[maxn];
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,1,n)pre[i]=1<<29;
	int k;read(k);rep(i,1,k){
		scanf("%s",s1+1);solve();
	}
	rep(i,1,n){
		if(pre[i]!=(1<<29)){
			f[i]=min(pre[i],f[i-1]+1);
		}else f[i]=f[i-1]+1;
	}
	int maxi=0;
	rep(i,1,n)maxi=max(maxi,f[i]);cout<<maxi<<' ';
	if(maxi==0){
		puts("0");return 0;
	}
	rep(i,1,n)if(f[i]==maxi){
		cout<<i-maxi<<endl;return 0;
	}
	return 0;
}