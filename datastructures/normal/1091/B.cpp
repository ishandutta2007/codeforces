#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
struct node{
	int x,y;
	bool operator <(const node &a)const{
		if (x!=a.x)return x<a.x;
		return y<a.y;
	}
};
node make_node(int x,int y){
	node ans;
	ans.x=x,ans.y=y;
	return ans;
}
map<node,int> c;
int n,x[1005],y[1005],a[1005],b[1005];
int ansx,ansy;
bool check(int p,int q){
	for (int i=1;i<=n;i++)
		if (c[make_node(p-x[i],q-y[i])]==0)return 0;
	return 1;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for (int i=1;i<=n;i++)cin>>a[i]>>b[i],c[make_node(a[i],b[i])]++;
	for (int i=1;i<=n;i++){
		ansx=x[1]+a[i],ansy=y[1]+b[i];
		if (check(ansx,ansy)){
			cout<<ansx<<' '<<ansy<<endl;
			return 0;
		}
	}
	return 0;
}