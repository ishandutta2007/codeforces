#include<bits/stdc++.h>
using namespace std;
bool p[100002];int n,m,k,a[100002],b[100002],c[100002];
int main(){
	cin>>n>>m>>k;int minx=1999999999;
	for(int i=1;i<=m;i++)cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=k;i++){int d;cin>>d;p[d]=true;}
	for(int i=1;i<=m;i++){if((p[a[i]]==true && p[b[i]]==false) || (p[a[i]]==false && p[b[i]]==true))minx=min(minx,c[i]);}
	if(minx==1999999999)minx=-1;
	cout<<minx<<endl;
	return 0;
}