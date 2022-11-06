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
	int T,n,x,y,i,ans=0;ll z;
	set<int>::iterator it;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		M.clear();
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			++M[a[i]];
		}
		sort(a+1,a+1+n);
		for(i=1;i<=n;++i){
			if(M[a[i]]){
				ll z=1LL*a[i]*x;
				if(z<=1000000000){
					if(M[z]){
						--M[z];
						--M[a[i]];
						++ans;
					}
				}
			}
		}
		printf("%d\n",n-ans*2);
		ans=0;
	}
	return 0;
}