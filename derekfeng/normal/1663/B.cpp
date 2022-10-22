#include<bits/stdc++.h>
using namespace std;
int a[9]={1200,1400,1600,1900,2100,2300,2400,2600,3000};
int main(){
	int x;scanf("%d",&x);
	for(int i=0;i<9;i++)if(a[i]>x){
		printf("%d",a[i]);
		return 0;
	}
}