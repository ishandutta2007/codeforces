#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <random>
using namespace std;
int n;
int book[2005][2005];
void out(){
	int num=0;
	for (int i=0;i<=2000;i++)
		for (int j=0;j<=2000;j++)
			num+=book[i][j];
	cout<<num<<endl;
	for (int i=0;i<=2000;i++)
		for (int j=0;j<=2000;j++)
			if (book[i][j]==1)cout<<i<<' '<<j<<endl;
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)book[i][i]=book[i][i-1]=book[i][i+1]=1;
	book[0][0]=book[0][1]=1;
	book[n+1][n]=book[n+1][n+1]=1;
	out();
	return 0;
}