#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
//orz mqy
int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	n=n%6;
	for (int i=n;i>=1;i--){
		if ((i&1)) {
			if (x==0) x=1; 
			else{
				if (x==1) x=0;
			}
		}
		else{
			if (x==1) x=2 ;
			else{
				if (x==2) x=1;
			} 
		}
		//cout<<x<<endl;
	}
	printf("%d\n",x);
	return 0;
}