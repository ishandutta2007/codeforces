#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
char s[1005];
int n;
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int nx=0,ny=0;
	for (int i=1;i<=n;i++){
		if (s[i]=='0'){
			cout<<1<<' '<<nx+1<<endl;
			nx=(nx+1)%4;
		}
		else{
			cout<<3<<' '<<2*(ny+1)-1<<endl;
			ny=(ny+1)%2;
		}
	}
	return 0;
}