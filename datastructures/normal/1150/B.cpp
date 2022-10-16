#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,num,book[55][55];
char a[55][55];
inline bool ok(int x,int y){
	if (x<1||y<1||x>n||y>n)return 0;
	if (book[x][y]==1||a[x][y]=='#')return 0;
	return 1;
} 
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
			if (a[i][j]=='.')num++;
		}
	for (int i=1;i<=n;i++)	
		for (int j=1;j<=n;j++){
			if (ok(i,j)&&ok(i-1,j)&&ok(i+1,j)&&ok(i,j-1)&&ok(i,j+1)){
				book[i][j]=book[i-1][j]=book[i][j-1]=book[i+1][j]=book[i][j+1]=1;
				num-=5;
			}
		}
	if (num==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}