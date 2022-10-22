#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef pair<db,int> pdi;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,st[1000004],t;
double num[1000004];
void add(double x){
	st[t]=1,num[t++]=x;
	while (t>1 && num[t-1]<=num[t-2]){
		num[t-2]=((double)(st[t-2])*num[t-2]+(double)(st[t-1])*num[t-1])/(double)(st[t-1]+st[t-2]);
		st[t-2]+=st[t-1];
		t--;
	}
}
int main(){
	read(n);
	for (int i=1;i<=n;i++){
		int x;read(x);
		add((double)(x));
	}
	for (int i=0;i<t;i++)
		while (st[i]--)
			printf("%.10lf\n",num[i]);
}