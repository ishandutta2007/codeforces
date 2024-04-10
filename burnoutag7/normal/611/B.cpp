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
LL n,m,bin[70],sum[70];
set<LL> t;
int main(){
	cin>>n>>m;
	bin[0]=1;
	sum[0]=1;
	for(int i=0;i<64;i++){
		bin[i+1]=bin[i]*2;
		sum[i]=bin[i+1]-1;
		for(int j=0;j<=i;j++){
			if(sum[i]-bin[j]>=n && sum[i]-bin[j]<=m && sum[i]!=bin[j]*2-1){
				t.insert(sum[i]-bin[j]);
			}
		}
	}
	cout<<t.size()<<endl;
	return 0;
}