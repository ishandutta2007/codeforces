//#include<bits/stdc++.h>
//using namespace std;
//const int n=100,k=3;
//int sg[n+1];
//int main(){
//	for(int i=0;i<=n;i++){
//		if(i>=1)sg[i]|=!sg[i-1];
//		if(i>=2)sg[i]|=!sg[i-2];
//		if(i>=k)sg[i]|=!sg[i-k];
//	}
//	for(int i=0;i<=n;i++)cout<<sg[i];
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int main(){
	int qu;
	scanf("%d",&qu);
	while(qu--){
		int n,k;
		scanf("%d%d",&n,&k);
		if(k%3)puts(n%3?"Alice":"Bob");
		else{
			int rd=k+1;
			n%=rd;
			puts(n%3||n==rd-1?"Alice":"Bob");
		}
	}
	return 0;
}
/*1
4
0 3
3 3
3 4
4 4
*/