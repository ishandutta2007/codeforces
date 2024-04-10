#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int h,w,num,ans;
char a[1005][1005];
signed main(){
	cin>>h>>w;
	for (int i=1;i<=h;i++)
		for (int j=1;j<=w;j++)cin>>a[i][j];
	for (int i=1;i<=h;i++)
		for (int j=1;j<=w;j++){
			if (a[i][j]=='*')num++;
			if (a[i][j]=='*'&&a[i-1][j]=='*'&&a[i][j-1]=='*'&&a[i+1][j]=='*'&&a[i][j+1]=='*'){
				num--;ans++;
				for (int k=j-1;k>=0;k--)
					if (a[i][k]!='*')break;
					else num--;
				for (int k=j+1;k<=w;k++)
					if (a[i][k]!='*')break;
					else num--;
				for (int k=i-1;k>=0;k--)
					if (a[k][j]!='*')break;
					else num--;
				for (int k=i+1;k<=h;k++)
					if (a[k][j]!='*')break;
					else num--;
			}
		}
	if (ans==1&&num==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}