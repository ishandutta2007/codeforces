#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
int i,j,k,n,m,T,a[maxn],t[maxn];
bool check(int x){
	priority_queue<int>Q;
	for(int i=1;i<=n;i++)
		if(a[i]>=x)Q.push(t[i]);
	while(Q.size()>x)Q.pop();
	if(Q.size()!=x)return false;
	int num=0;
	while(!Q.empty())num+=Q.top(),Q.pop();
	return num<=m;
}
bool check2(int x){
	priority_queue<pii>Q;
	for(int i=1;i<=n;i++)
		if(a[i]>=x)Q.push(make_pair(t[i],i));
	while(Q.size()>x)Q.pop();
	if(Q.size()!=x)return false;
	cout<<Q.size()<<endl;
	int num=0;
	while(!Q.empty())printf("%d ",Q.top().second),Q.pop();
	return num<=m;
}
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++){
		a[i]=read();
		t[i]=read();
	}
	int L=1,R=n;
	while(L<=R){
		int Mid=(L+R)>>1;
		if(check(Mid))L=Mid+1;
		else R=Mid-1;
	}cout<<L-1<<endl;
	check2(L-1);
	return 0;
}