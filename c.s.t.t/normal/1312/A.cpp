#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int main(){
	scanf("%d",&T);
	while(T--)scanf("%d%d",&n,&m),puts(n%m?"No":"Yes");
	return 0;
}