#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,m,a[200005],x,l,r;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=m;i++){
		cin>>x;
		l=1;
		r=n;
		while(l<r-1){
			LL mid=(l+r)/2;
			if(a[mid]>=x){
				r=mid;
			}else{
				l=mid;
			}
		}
		if(a[l]>=x){
			r=l;
		}
		cout<<r<<' '<<x-a[r-1]<<endl;
	}
	return 0;
}