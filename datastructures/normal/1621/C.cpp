#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int t,n,cnt;
int c[10005],tot;
int pre(int id){
	if (id==1)return tot;
	return id-1;
}
int nxt(int id){
	if (id==tot)return 1;
	return id+1;
}
int p[10005],book[10005];
int ask(int x){
	int ans;
	cout<<"? "<<x<<endl;
	cin>>ans;
	return ans;
}
void work(){
	int qwq=cnt;
	int fir=1;
	while(book[fir]==1)fir++;
	int awa=ask(fir);
	tot=0;
	while(awa!=c[1]||tot==0){
		c[++tot]=awa;
		awa=ask(fir);
	}
	cnt+=tot;
	int now=1;
	for (int i=1;i<=qwq;i++)now=pre(now);
	for (int i=1;i<=tot;i++)p[c[now]]=c[nxt(now)],now=nxt(now);
	for (int i=1;i<=tot;i++)book[c[i]]=1;
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(book,0,sizeof(book));
		cnt=0;
		while(cnt<n)work();
		cout<<"! ";
		for (int i=1;i<=n;i++)cout<<p[i]<<' ';
		cout<<endl;
	}
	return 0;
}