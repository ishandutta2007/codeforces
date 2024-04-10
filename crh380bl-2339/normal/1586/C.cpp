#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int n,m;
int id(int i,int j){
	return (i-1)*m+j;
}
//char s[1000010];
string s[1000002];
int a[1000010];
int main(){
	read(n);read(m);
	int i,j,k,x,y;
	for(i=1;i<=n;++i){
		cin>>s[i];
	}
	for(i=2;i<=n;++i){
		for(j=1;j<m;++j){
			if(s[i][j-1]=='X'&&s[i-1][j]=='X'){
				a[j]=1;
			}
		}
	}
	//for(j=1;j<=m;++j)printf("%d ",a[j]);
	for(j=2;j<=m;++j)a[j]+=a[j-1];
	int q;
	read(q);
	while(q--){
		read(x);read(y);
		if(a[y-1]!=a[x-1])puts("NO");
		else puts("YES");
	}
	return 0;
}