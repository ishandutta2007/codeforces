#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a,b;
int main(){
	int n,sum=0,s=0; scanf("%d",&n); a.resize(n);
	for(int i=0;i<a.size();++i) scanf("%d",&a[i]),s+=a[i];
	sum=a[0]; b.push_back(0);
	for(int i=1;i<a.size();++i)
		if(a[i]*2<=a[0]){
			b.push_back(i);
			sum+=a[i];
		}
	if(sum*2<=s) puts("0");
	else{
		printf("%d\n",(int)b.size());
		for(auto i:b) printf("%d ",i+1);
	}
	return 0;
}