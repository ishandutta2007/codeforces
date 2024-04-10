#include<bits/stdc++.h>
using namespace std;
int n,m,dat[1000003];
string s[1003];
int query(int x){
	int ret=0;
	while(x){
		ret+=dat[x];
		x-=(x&-x);
	}return ret;
}
void add(int x,int y){
	while(x<=1000000){
		dat[x]+=y;
		x+=(x&-x);
	}
}
int main(){int q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++)
			if(s[i][j]=='*')
				add(j*n+i+1,1);
	}
	while(q--){
		int x,y;
		cin>>x>>y;x--;y--;
		if(s[x][y]=='*')s[x][y]='.',add(y*n+x+1,-1);
		else s[x][y]='*',add(y*n+x+1,1); 
		cout<<query(1000000)-query(query(1000000))<<endl;
	}
}