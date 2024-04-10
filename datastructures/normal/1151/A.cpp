#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
inline int work(char a,char b){
	int aa=a-'A',bb=b-'A';
	if (aa>bb)return min(aa-bb,bb+26-aa);
	return min(bb-aa,aa+26-bb);
}
int n,ans=2e9;
string x;
signed main(){
	cin>>n>>x;
	for (int i=0;i+3<x.size();i++)
		ans=min(ans,work(x[i],'A')+work(x[i+1],'C')+work(x[i+2],'T')+work(x[i+3],'G'));
	cout<<ans<<endl;
	return 0;
}