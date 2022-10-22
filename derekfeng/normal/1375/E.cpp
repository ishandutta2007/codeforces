#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0'); 
}
void output(int x,int y){
	write(x),putchar(' '),write(y),puts("");
}
int n,a[1003],cnt,pos[1003];
map<pii,int>mp;
vector<pii>res;
int main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),mp[mkp(a[i],i)]=1;
	for(map<pii,int>::iterator it=mp.begin();it!=mp.end();it++)a[it->first.second]=++cnt,pos[cnt]=it->first.second;
	for(int i=n;i>=1;i--){
		int cur=a[i];
		for(int j=cur+1;j<=i;j++){
			res.push_back(mkp(pos[j],i));
			int p1=pos[j],p2=i;
			pos[a[p1]]=p2,pos[a[p2]]=p1;
			swap(a[p1],a[p2]);
		}
	}
	write(res.size()),puts("");
	for(int i=0;i<res.size();i++)output(res[i].fi,res[i].se);
}