#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=1000010;
int i,j,k,n,m,T,is[maxn],sum[maxn];
vector<int>a[maxn];
int main(){
	n=read();m=read();
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			char c;
			do c=getchar();
			while(c!='.' && c!='X');
			a[i].push_back(c=='.'?1:0);
//			cout<<i<<' '<<j<<' '<<a[i][j-1]<<endl;
		}
	for(i=2;i<=n;i++)
		for(j=1;j<m;j++){
			//cout<<i<<' '<<j<<endl;
			if(!a[i][j-1] && !a[i-1][j])is[j]=1;
		}
	for(i=1;i<=m;i++)is[i]+=is[i-1];
	int q=read();
	while(q--){
		int a=read(),b=read();
//		cout<<is[b-1]<<' '<<is[a]<<endl;
		if(a==b)puts("YES");
		else if(is[b-1]-is[a-1]==0)puts("YES");
		else puts("NO");
	}
}