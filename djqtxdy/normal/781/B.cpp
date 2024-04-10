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
set<string> u1,u2;
vector<string> res;
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		string a,b,c,d;
		cin>>a>>b;
		d=a.substr(0,3);
		c=a.substr(0,2)+b[0];
	//	cout<<c<<d<<endl;
		if (u1.find(c)!=u1.end()){
			if (u1.find(d)!=u1.end() || u2.find(d)!=u2.end()){
				printf("NO\n");
				return 0;
			}
			u1.insert(d);
			res.push_back(d);
		}
		else{
			u2.insert(d);
			u1.insert(c);
			res.push_back(c);
		}
	}
	printf("YES\n");
	for (int i=0;i<n;i++){
		printf("%s\n",res[i].c_str());
	}
	return 0;
}