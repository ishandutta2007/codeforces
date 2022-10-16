#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int n,a[300005],pos[300005],tot,l[3000005],r[3000005];
void swp(int x,int y){
	++tot;
	l[tot]=x,r[tot]=y;
	swap(a[x],a[y]);
	pos[a[x]]=x,pos[a[y]]=y;
	return;
}
void work(int x,int y){
	if (x>y)swap(x,y);
	if (x>n/2){
		swp(x,1);
		swp(y,1);
		swp(x,1);
	}
	else if (y<=n/2){
		swp(x,n);
		swp(y,n);		
		swp(x,n);
	}
	else{
		if (y-x>=n/2)swp(x,y);
		else{
			swp(y,1);
			swp(x,n);
			swp(1,n);
			swp(1,y);
			swp(n,x);
		}
	}
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
	for (int i=1;i<=n;i++){
		if (pos[i]!=i)work(pos[i],i);
	}
	cout<<tot<<endl;
	for (int i=1;i<=tot;i++)printf("%d %d\n",l[i],r[i]);
	return 0;
}