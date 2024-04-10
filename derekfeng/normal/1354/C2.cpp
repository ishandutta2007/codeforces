#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db PI=3.1415926535796;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
int T,n;
int main(){
	read(T);
	while(T--)read(n),printf("%.6lf\n",cos(PI/4/n)/sin(PI/2/n));
}