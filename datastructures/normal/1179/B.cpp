#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,m,x1,x2;
signed main(){
	cin>>n>>m;
	for (x1=1,x2=n;x1<=x2;x1++,x2--){
		if (x1==x2){
			int l=1,r=m;
			for (int i=1;i<=m;i++)
				if (i%2==1)printf("%d %d\n",x1,l),l++;
				else printf("%d %d\n",x1,r),r--;
			break;
		}
		int l=1,r=m;
		if (x1%2==1){
			for (int i=1;i<=2*m;i++){
				if (i%2==1)printf("%d %d\n",x1,l),l++;
				else printf("%d %d\n",x2,r),r--;
			}
		}
		else{
			for (int i=1;i<=2*m;i++){
				if (i%2==1)printf("%d %d\n",x1,r),r--;
				else printf("%d %d\n",x2,l),l++;
			}
		}
	}
}