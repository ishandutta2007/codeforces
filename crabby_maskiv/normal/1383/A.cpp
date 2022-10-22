#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const int M=25;
int n,m,len;
char a[N],b[N];
int fa[M];
int rt(int x){
	if(fa[x]==x) return x;
	return fa[x]=rt(fa[x]);
}
int ans;
inline void merge(int x,int y){
	x=rt(x),y=rt(y);
	if(x==y){
		ans--;
		return;
	}
	fa[x]=y;
}
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		cin>>(a+1)>>(b+1);
		for(i=1;i<=n;i++){
			if(a[i]>b[i]){
				cout<<-1<<endl;
				break;
			}
		}
		if(i<=n) continue;
		ans=n;
		for(i=1;i<=20;i++) fa[i]=i;
		for(i=1;i<=n;i++)
			merge(a[i]-'a'+1,b[i]-'a'+1);
		cout<<ans<<endl;
	}
	return 0;
}