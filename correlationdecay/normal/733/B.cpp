#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#define maxn 1000009
using namespace std;
const int INF=1e9;
int n,l[maxn],r[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i];
	int suml=0,sumr=0;
	for(int i=1;i<=n;i++){
		suml+=l[i];
		sumr+=r[i];
	}
	int cur=abs(suml-sumr);
	int ans=0;
	for(int i=1;i<=n;i++){
		suml-=l[i];
		sumr-=r[i];
		suml+=r[i];
		sumr+=l[i];
		if(abs(suml-sumr)>cur){
			cur=abs(suml-sumr);
			ans=i;
		}
		suml-=r[i];
		sumr-=l[i];
		suml+=l[i];
		sumr+=r[i];
	}
	cout<<ans<<endl;
	//system("pause");
	return 0;
}