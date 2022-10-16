#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int w1,w2,h1,h2;
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>w1>>h1>>w2>>h2;
	cout<<w1+2+w2+2+h1*2+h2*2+w1-w2<<endl;
	return 0;
}