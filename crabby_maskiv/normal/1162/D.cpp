#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f;
const ll mod=1000000007;
int n,m;
vector<int> v[N],V[N];
int nxt[N];
bool eq(const vector<int> &v1,const vector<int> &v2){
	if(v1.size()!=v2.size()) return 0;
	for(int i=0;i<v1.size();i++)
		if(v1[i]!=v2[i]) return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		v[x].push_back(y-x);
		v[y].push_back(x-y+n);
	}
	for(i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
	for(i=1;i<=n;i++){
		for(j=0;j<v[i].size();j++){
			V[i].push_back(v[i][j]);
			V[n+i].push_back(v[i][j]);
		}
	}
	int leng=n*2,len=n;
	for(i=2;i<=len;i++){
		int p=i-1;
		while(p>0){
			if(eq(v[nxt[p]+1],v[i])){
				nxt[i]=nxt[p]+1;
				break;
			}
			else p=nxt[p];
		}
	}
	j=1;
	for(i=2;i<leng;i++){
		if(eq(V[i],v[j])){
			j++;
			if(j>len){
				cout<<"Yes";
				return 0;
			}			
		}
		else{
			while(j>1&&!eq(V[i],v[j])) j=nxt[j-1]+1;
			j++;
		}
	}
	cout<<"No";
	return 0;
}