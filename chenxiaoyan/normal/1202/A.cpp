#include<bits/stdc++.h>
using namespace std;
const int N=100000,M=100000;
int n,m;
char a[N+5],b[M+5];
void mian(){
	cin>>a+1>>b+1;//
	n=strlen(a+1);m=strlen(b+1);
	int l1=0;
	for(int i=m;;i--)if(b[i]=='1'){l1=n-(m-i);break;}
	for(int i=l1;;i--)if(a[i]=='1'){printf("%d\n",l1-i);return;}	
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
/*1
4
1010
11
10001
110
1
1
1010101010101
11110000
*/