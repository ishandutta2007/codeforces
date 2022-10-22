#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
int n,m,k,ans;
bool occ[2005][2005];
char c;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			while(scanf("%c",&c) && c=='\n');
			if(c == '*') occ[i][j] = true;
		}
	}
	
	for(int i=1;i<=n;i++){
		int con = 0;
		for(int j=1;j<=m;j++){
	 		if(!occ[i][j]) con++;
			else con = 0;
			if(con >= k) ans++;
		}
	}
	
	if(k > 1)
	for(int j=1;j<=m;j++){
		int con = 0;
		for(int i=1;i<=n;i++){
			if(!occ[i][j]) con++;
			else con = 0;
			if(con >= k) ans++;
		}
	}

	printf("%d\n",ans);
	return 0;
}