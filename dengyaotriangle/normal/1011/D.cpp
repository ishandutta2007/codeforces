#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=40;

int d[maxn];
int m,n;
bool v[maxn];
int main(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cout<<m<<endl;
		fflush(stdout);
		cin>>d[i];
		if(d[i]==0) return 0;
		if(d[i]==-2) return 0;
		if(d[i]==-1) v[i]=1;
		else v[i]=0;
	}
	int minv=1,maxv=m-1;
	int cnt=0;
	while(true){
		int mid=(minv+maxv)/2;
		cout<<mid<<endl;
		fflush(stdout);
		int ver;
		cin>>ver;
		if(ver==0) return 0;
		if(ver==-2) return 0;
		if(!v[cnt%n]) ver=0-ver;
		if(ver==-1){
			maxv=mid-1;
		}
		if(ver==1){
			minv=mid+1;
		}
		cnt++;
	}
}