#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,a[55][55],pos;
inline int qry(register int X1,register int Y1,register int X2,register int Y2){
	register int opt=0;
	cout<<'?'<<' '<<X1<<' '<<Y1<<' '<<X2<<' '<<Y2<<endl;
	fflush(stdout);
	cin>>opt;
	return opt;
}
inline void out(){
	cout<<'!'<<endl;
	for (register int i=1;i<=n;i++){
		for (register int j=1;j<=n;j++)cout<<a[i][j];
		cout<<endl;
	}
	return;
}
inline void change(){
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++)
			if ((i+j)%2==1)a[i][j]=a[i][j]^1;
	return;
}
int main(){
	cin>>n;
	memset(a,-1,sizeof(a));
	a[1][1]=1,a[n][n]=0;
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++){
			if (i==1&&j==1)continue; 
			if (i==n&&j==n)continue;
			if ((i+j)%2==1)continue;
			if (i==1)a[i][j]=a[i][j-2]^1^qry(i,j-2,i,j);
			else if (j==1)a[i][j]=a[i-2][j]^1^qry(i-2,j,i,j);
			else a[i][j]=a[i-1][j-1]^1^qry(i-1,j-1,i,j);
		}
	a[1][2]=1;
	for (register int i=1;i<=n;i++)
		for (register int j=2;j<=n;j++){
			if (i==1&&j==2)continue; 
			if ((i+j)%2==0)continue;
			if (i==1)a[i][j]=a[i][j-2]^1^qry(i,j-2,i,j);
			else if (j==2)a[i][j]=a[i-2][j]^1^qry(i-2,j,i,j);
			else a[i][j]=a[i-1][j-1]^1^qry(i-1,j-1,i,j);
		}
	a[2][1]=a[2][3]^1^qry(2,1,2,3);
	for (register int i=4;i<=n;i+=2)a[i][1]=a[i-2][1]^1^qry(i-2,1,i,1);
	for (pos=n-2;pos>=1;pos-=2)
		if (a[pos][pos]==1)break;
	if (a[pos][pos+2]!=a[pos+1][pos+1]){
		if (qry(pos,pos,pos+1,pos+2)!=a[pos+1][pos+2])change();
		out();
		return 0;
	}
	if (a[pos+1][pos+1]!=a[pos+2][pos]){
		if (qry(pos,pos,pos+2,pos+1)!=a[pos+2][pos+1])change();
		out();
		return 0;
	}
	if (a[pos][pos+1]==a[pos+1][pos+2]){
		if (a[pos+1][pos+1]==0&&qry(pos,pos+1,pos+2,pos+2)==a[pos][pos+1])change();
		if (a[pos+1][pos+1]==1&&qry(pos,pos,pos+1,pos+2)!=a[pos+1][pos+2])change();
		out();
		return 0;
	}
	if (a[pos][pos+1]!=a[pos+1][pos+2]){
		if (a[pos+1][pos+1]==0&&qry(pos,pos,pos+1,pos+2)!=a[pos+1][pos+2])change();
		if (a[pos+1][pos+1]==1&&qry(pos,pos+1,pos+2,pos+2)==a[pos][pos+1])change();
		out();
		return 0;
	}
	return 0;
}