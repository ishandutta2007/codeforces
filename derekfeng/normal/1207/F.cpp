#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <ios>
using namespace std;
int q;
int a[500004],dp[710][710];
void read(int &x){
	char ch=getchar();x=0;
	int res=1;
	for (;ch==' '||ch=='\n';ch=getchar());
	if (ch=='-') res=-1,ch=getchar();
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
	x*=res;
}
int oper,x,y;
int main(){
	read(q);
	while (q--){
		read(oper),read(x),read(y);
		if (oper==1){
			a[x]+=y;
			for (int i=1;i<710;i++) dp[i][x%i]+=y;
		}else{
			if (x<710)
				printf("%d",dp[x][y]);
			else{
				int res=0;
				for (int i=y;i<=500000;i+=x) res+=a[i];
				printf("%d",res);
			}
			puts("");
		}
	}
}