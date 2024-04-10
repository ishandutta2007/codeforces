#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,m,a[505][505];
int q[505][2],s[505],book[505];
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=0;i<=10;i++){
		memset(q,-1,sizeof(q));
		for (int j=1;j<=n;j++)
			for (int k=1;k<=m;k++)
				if ((a[j][k]&(1<<i))!=0)q[j][1]=k;
				else q[j][0]=k;
		memset(book,0,sizeof(book));
		int tot=0;
		for (int j=1;j<=n;j++)
			if (q[j][1]!=-1&&q[j][0]!=-1)book[j]=1,tot++;
		int num=0;
		for (int j=1;j<=n;j++)
			if (q[j][1]!=-1&&book[j]==0)num++;
		if (num%2!=0){
			cout<<"TAK"<<endl;
			for (int j=1;j<=n;j++){
				if (q[j][0]!=-1)cout<<q[j][0]<<' ';
				else cout<<q[j][1]<<' ';
			}
			return 0;
		}
		else{
			if (tot==0)continue;
			cout<<"TAK"<<endl;
			int flag=1;
			for (int j=1;j<=n;j++){
				if (flag==1&&book[j]==1){
					flag=0;
					cout<<q[j][1]<<' ';
					continue;
				}
				if (q[j][0]!=-1)cout<<q[j][0]<<' ';
				else cout<<q[j][1]<<' ';
			}
			return 0;
		}
	}
	cout<<"NIE"<<endl;
	return 0;
}