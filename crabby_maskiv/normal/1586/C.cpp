#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e6+5;
int n,m;
char a[N];
inline bool f(int x,int y){
	return (a[(x-1)*m+y]=='X');
}
int b[N];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",a+(i-1)*m+1);
	for(i=2;i<=n;i++){
		for(j=2;j<=m;j++)
			if(f(i-1,j)&&f(i,j-1)) b[j]++;
	}
	for(i=2;i<=m;i++) b[i]+=b[i-1];
	int q;scanf("%d",&q);
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		puts((b[r]-b[l])?"NO":"YES");
	}
	return 0;
}