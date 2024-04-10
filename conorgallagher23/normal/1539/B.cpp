#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
int read(){
	char ch=getchar(); int x=0,fl=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-'0');
	return x*fl;
}
const int N=100005;

int n,q,p[N];
char s[N];

int main(){
	n=read(); q=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) p[i]=p[i-1]+(s[i]-'a'+1);
	while(q--){
		int l=read(),r=read();
		cout<<p[r]-p[l-1]<<'\n';
	}
	return 0;
}