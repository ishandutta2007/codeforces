#include<iostream>
#include<vector>
using namespace std;
#define R register int
string A[1000000];
bool vis[1000000];
int pre[1000000];
int main(){
	int n,m,q,l,r;
	cin>>n>>m;
	for(R i=0;i!=n;i++){
		cin>>A[i];
	}
	for(R i=0;i!=n-1;i++){
		for(R j=0;j!=m-1;j++){
			if(A[i][j+1]=='X'&&A[i+1][j]=='X'){
				vis[j]=true;
			}
		}
	}
	pre[0]=-1;
	for(R i=1;i!=m;i++){
		pre[i]=pre[i-1];
		if(vis[i-1]==true){
			pre[i]=i-1;
		}
	}
	cin>>q;
	for(R i=0;i!=q;i++){
		cin>>l>>r;
		l--;
		r--;
		if(l==r||pre[r]<l){
			cout<<"Yes"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}