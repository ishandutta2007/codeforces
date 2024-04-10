#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
map<string,int>vis;
int score[60]={0,25,18,15,12,10,8,6,4,2,1};
int n,m,tot;
string tmp,player[1010];
int p[1010][60],f[1010],arr[1010];
bool cmp(int a,int b){
	if(f[a]!=f[b])return f[a]>f[b];
	rep(j,1,50){
		if(p[a][j]!=p[b][j])return p[a][j]>p[b][j];
	}
	return false;
}
bool cmp2(int a,int b){
	if(p[a][1]!=p[b][1])return p[a][1]>p[b][1];
	if(f[a]!=f[b])return f[a]>f[b];
	rep(j,2,50){
		if(p[a][j]!=p[b][j])return p[a][j]>p[b][j];
	}
	return false;
}
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>m;
		rep(j,1,m){
			cin>>tmp;
			if(!vis[tmp]){
				tot++;vis[tmp]=tot;player[tot]=tmp;arr[tot]=tot;
			}
			f[vis[tmp]]+=score[j];
			p[vis[tmp]][j]++;
		}
	}
	sort(arr+1,arr+1+tot,cmp);
	cout<<player[arr[1]]<<endl;
	sort(arr+1,arr+1+tot,cmp2);
	cout<<player[arr[1]]<<endl;
	return 0;
}