#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
const int $=555555;
int n,m,c[133]; string s[$],r[$];
int main(){
	int t;cin>>t;while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)cin>>s[i];
		for(int i=1;i<n;++i)cin>>r[i];
		for(int i=0;i<m;++i){
			for(int j=1;j<=n;++j)c[s[j][i]]++;
			for(int j=1;j<n;++j)c[r[j][i]]--;
			for(char C='a';C<='z';++C)if(c[C])putchar(C),c[C]=0;
		}puts("");
	}
}