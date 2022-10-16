#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
int n,a[100005],ans;
map<int,int> c;
int d[200005];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=-50;i<=50;i++){
		c.clear();
		for (int j=1;j<=n;j++)c[a[j]+i*j]++,ans=max(ans,c[a[j]+i*j]); 
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=min(n,i+2000);j++){
			if ((a[j]-a[i])%(j-i)==0){
				d[(a[j]-a[i])/(j-i)+100000]++;
				ans=max(ans,d[(a[j]-a[i])/(j-i)+100000]+1);
			}
		}
		for (int j=i+1;j<=min(n,i+2000);j++)
			if ((a[j]-a[i])%(j-i)==0)
				d[(a[j]-a[i])/(j-i)+100000]--;
	}
	cout<<n-ans<<endl;
	return 0;
}