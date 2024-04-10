#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int t,n,x,a[200005];
map<int,int> c;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>x;
		c.clear();
		for (int i=1;i<=n;i++)scanf("%d",&a[i]),c[a[i]]++;
		sort(a+1,a+1+n);
		int num=0;
		for (int i=n;i>=1;i--)
			if (a[i]%x==0&&c[a[i]]>0&&c[a[i]/x]>0){
				num++;
				c[a[i]]--;
				c[a[i]/x]--;
			}
		cout<<n-2*num<<endl;
	}
	return 0;
}