#include<bits/stdc++.h>
#define ll long long
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
map<int,int>M;
int a[200005];
int main(){
	int T;
	scanf("%d",&T);
	int n,x,j,k,i; 
	while(T--){
		scanf("%d%d",&n,&k);
		M.clear();
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			M[a[i]]=1;
		}
		bool flg=0;
		for(i=1;i<=n;++i){
			x=a[i]+k;
			if(M[x]){
				flg=1;
				break;
			}
		}
		if(flg){
			puts("YES");
		}
		else puts("NO");
	}
	return 0;
}