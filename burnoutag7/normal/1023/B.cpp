/******************
*  Writer: Oh no  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
typedef long long LL;
LL n,k;
LL a,b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	a=max(1LL,k-n);
	b=(k-1)/2;
	cout<<max(0LL,b-a+1);
	return 0;
}