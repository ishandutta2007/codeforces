#include <iostream>
#include <cstdio>
using namespace std;
int a[15][15],num[15][15],to[105];
double f[105];
int main(){
	for (int i=1;i<=10;i++)
		for (int j=1;j<=10;j++)
			cin>>a[i][j];
	for (int i=10;i>=1;i--){
		if (i%2==0){
			for (int j=1;j<=10;j++)
				num[i][j]=10*(10-i)+j;
		} 
		else{
			for (int j=10;j>=1;j--)
				num[i][j]=10*(10-i)+(10-j+1); 
		}
 	} 
 	for (int i=1;i<=10;i++)
 		for (int j=1;j<=10;j++)
 			to[num[i][j]]=num[i-a[i][j]][j];
 	f[100]=0;
 	for (int i=99;i>=1;i--){
 		if (i>94){
 			f[i]=1.0;
 			for (int j=i+1;j<=100;j++)
 				f[i]+=f[j]/6.0;
 			f[i]*=6.0/(100-i);
		 }
		 else{
		 	f[i]=1.0;
		 	for (int j=i+1;j<=i+6;j++)
		 		f[i]+=min(f[j],f[to[j]])/6.0;
		 }
	}
	printf("%.9lf\n",f[1]);
	return 0;
}