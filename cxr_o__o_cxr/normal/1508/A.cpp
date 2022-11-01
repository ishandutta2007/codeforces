//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2e5+4;
int n,mx,a[N],c[2];
char s[3][N];
vector<int>vec[2];
inline void ran(char *s1,char *s2,int o){
	for(int i=1,x=0,y=0;i<=n*2+1;i++){
		if(s1[i]==o||i>n*2){
			mx=++y;
			a[y]=max(a[y],x);
			x=0;
		}
		else x++;
	}
	for(int i=1,x=0,y=0;i<=n*2+1;i++){
		if(s2[i]==o||i>n*2){
			++y;
			mx=max(mx,y);
			a[y]=max(a[y],x);
			x=0;
		}
		else x++;
	}
	for(int i=1;i<=mx;i++){
		for(int j=1;j<=a[i];j++)cout<<(o^1);
		if(i!=mx)cout<<o;
	}
	puts("");
}
inline void solve(){
	vec[0].clear();vec[1].clear();
	memset(a,0,sizeof(int)*(n*2+1));
	n=read();
	scanf("%s%s%s",s[0]+1,s[1]+1,s[2]+1);
	for(int t=0;t^3;t++){
		c[0]=c[1]=0;
		for(int i=1;i<=n*2;i++){
			s[t][i]&=1;
			c[s[t][i]]++;
		}
		if(c[0]>=n)vec[0].push_back(t);
		if(c[1]>=n)vec[1].push_back(t);
	}
	if(vec[0].size()>1)ran(s[vec[0][0]],s[vec[0][1]],0);
	else ran(s[vec[1][0]],s[vec[1][1]],1);
}
int main(){
	for(int T=read();T--;)solve();
	return (0-0);
}