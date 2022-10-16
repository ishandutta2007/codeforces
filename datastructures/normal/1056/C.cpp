#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,type,p[10005];
struct node{
	int a,b;
}c[10005];
int awa[10005];
int book[10005];
void qwq(int x){
	int y;
	cout<<x<<endl;
	cin>>y;
	book[x]=book[y]=1;
	return;
}
int getid(){
	int mx=0,id=0;
	for (int i=1;i<=2*n;i++)
		if (book[i]==0&&p[i]>mx)mx=p[i],id=i;
	return id;
}
bool check(){
	for (int i=1;i<=2*n;i++)
		if (book[i]==0)return 1;
	return 0;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=2*n;i++)cin>>p[i];
	for (int i=1;i<=m;i++)cin>>c[i].a>>c[i].b;
	cin>>type;
	if (type==1){
		for (int i=1;i<=m;i++){
			if (p[c[i].a]>p[c[i].b])qwq(c[i].a);
			else qwq(c[i].b);
		}
		for (int i=1;i<=2*(n-m);i++)qwq(getid());
	}
	else{
		for (int i=1;i<=m;i++)awa[c[i].a]=c[i].b,awa[c[i].b]=c[i].a;
		while(check()){
			int x;
			cin>>x;
			if (awa[x]==0){
				for (int j=1;j<=m;j++)
					if (book[c[j].a]==0){
						if (p[c[j].a]>p[c[j].b])qwq(c[j].a);
						else qwq(c[j].b);
					}
				book[x]=1;
				int y=getid();
				cout<<y<<endl;
				book[y]=1;
			}
			else{
				int y=awa[x];
				cout<<y<<endl;
				book[x]=book[y]=1;
			}
		}
	}
	return 0;
}