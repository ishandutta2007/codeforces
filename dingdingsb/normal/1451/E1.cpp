#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int a,b,c;
}f[2][2][2][2][2];
int ans[(1<<16)+10];
int get(int x,int y){
	return (x>>y)&1;
}
signed main(){
	cin>>n;
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++)
				f[i&j][i|j][i&k][i|k][j&k]=(node){i,j,k};
	cout<<"AND 1 2\n";
	cout.flush();
	int a;cin>>a;
	cout<<"OR 1 2\n";
	cout.flush();
	int b;cin>>b;
	cout<<"AND 1 3\n";
	cout.flush();
	int c;cin>>c;
	cout<<"OR 1 3\n";
	cout.flush();
	int d;cin>>d;
	cout<<"AND 2 3\n";
	cout.flush();
	int e;cin>>e;
	for(int i=0;i<16;i++){
		ans[1]+=(1<<i)*f[get(a,i)][get(b,i)][get(c,i)][get(d,i)][get(e,i)].a;
		ans[2]+=(1<<i)*f[get(a,i)][get(b,i)][get(c,i)][get(d,i)][get(e,i)].b;
		ans[3]+=(1<<i)*f[get(a,i)][get(b,i)][get(c,i)][get(d,i)][get(e,i)].c;
	}
	for(int i=4;i<=n;i++){
		cout<<"XOR "<<i<<" "<<i-1<<endl;
		cout.flush();
		int f;cin>>f;
		ans[i]=ans[i-1]^f;
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" "; 
	return 0;
}