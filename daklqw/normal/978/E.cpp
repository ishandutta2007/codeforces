#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 1010
int n,w,a[MAXN];
int main(){
	cin>>n>>w;
	int minn=0,maxn=0,now=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		now+=a[i];
		minn=min(now,minn);
		maxn=max(now,maxn);
	}
	int x,y;
	x=-minn;
	y=w-maxn;
	if(x>y)cout<<0<<endl;
	else cout<<y-x+1<<endl;
	return 0;
}