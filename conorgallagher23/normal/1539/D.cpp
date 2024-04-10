#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
LL read(){
	char ch=getchar(); LL x=0,fl=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-'0');
	return x*fl;
}
const int N=100005;

int n;
LL ans,w;
struct node{
	LL x,y;
}a[N];

int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),w+=a[i].x;
	sort(a+1,a+n+1,[&](node a,node b){return a.y<b.y;});
	LL l=1,r=n,c=0LL;
	while(l<=r){
		if(l==r){
			LL res=max(a[l].y-c,0LL);
			ans+=max(a[l].x-res,0LL);
			break;
		}
		if(c<a[l].y){
			LL dat=min(a[l].y-c,a[r].x);
			a[r].x-=dat;
			c+=dat;
			if(!a[r].x) r--;
		}
		else{
			c+=a[l].x;
			ans+=a[l].x;
			l++;
		}
	}
	cout<<w*2LL-ans<<'\n';
	return 0;
}