#include <iostream>
#include <map>
#include <cstdlib>
#include <string>
#define rep(i,j,k) for(i=j;i<k;i++)
#define N 100000+10
typedef long long ll;
using namespace std;

int n,m,q,i,j,x,y,x1,y1,A[N],B[N];
string st,a,b;
map<string,int> mp;

int find(int x){
	if (!x) return 0;
	if (A[x]!=x) A[x]=find(A[x]);
	return A[x];
}

int main(){
	cin>>n>>m>>q;
	rep(i,1,n+1)cin>>st,mp[st]=i,A[i]=i;
	rep(i,0,m){
		cin>>j>>a>>b;
		x=find(mp[a]),y=find(mp[b]);
		x1=find(B[x]),y1=find(B[y]);
		if(j==1){
			if(x1!=y){
				cout<<"YES"<<endl;
				A[x]=y;
				if(x1&&y1)A[x1]=y1;
				if(!y1)B[y]=x1;
			}
			else
				cout<<"NO"<<endl;
		}
		else{
			if(x!=y){
				cout<<"YES"<<endl;
				if(x1)A[y]=x1;
				else B[x]=y;
				if(y1)A[x]=y1;
				else B[y]=x;
			}
			else
				cout<<"NO"<<endl;
		}
	}
	while(q--){
		cin>>a>>b;
		x=find(mp[a]),y=find(mp[b]);
		x1=find(B[x]);
		if(x==y)cout<<'1'<<endl;
		else{
			if(x1==y)cout<<'2'<<endl;
			else cout<<'3'<<endl;
		}
	}	
	return 0;
}