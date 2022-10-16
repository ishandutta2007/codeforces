#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <random>
#define int long long
using namespace std;
int k;
int awa=1;
int num[10];
string qwq="codeforces";
signed main(){
	cin>>k;
	for (int i=0;i<10;i++)num[i]=1;
	int p=0;
	while(awa<k){
		awa=awa/num[p]*(num[p]+1);
		num[p]++;
		p++;
		if (p==10)p=0;
	}
	for (int i=0;i<10;i++)
		for (int j=1;j<=num[i];j++)cout<<qwq[i];
	cout<<endl;
	return 0;
}