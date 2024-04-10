#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int a[100000];
bool chk(int n){
	int i;
	for(i=2;i<=n;++i){
		if(a[i-1]>a[i])return 1;
	}
	return 0;
}
int main(){
	int t,n,i;
	read(t);
	while(t--){
		read(n);
		for(i=1;i<=n;++i)scanf("%d",&a[i]);
		if(chk(n))puts("YES");
		else puts("NO");
	} 
	return 0;
}