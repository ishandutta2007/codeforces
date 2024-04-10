#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#define maxn 10009
#define PS system("pause");
using namespace std;
int n,k;
char s[maxn];
bool vis[maxn];
void dfs(int u){
	vis[u]=1;
	if(u+k<n&&!vis[u+k]&&s[u+k]!='#')
		dfs(u+k);
	if(u-k>=0&&!vis[u-k]&&s[u-k]!='#')
		dfs(u-k);
}
int main(){
	cin>>n>>k;
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]=='G'){
			dfs(i);
		}
	}
	bool ok=0;
	for(int i=0;i<n;i++){
		if(s[i]=='T')
			ok=vis[i];
	}
	if(ok)
		puts("YES");
	else
		puts("NO");
	//PS;
	return 0;
}