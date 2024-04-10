#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int t,n,a,b;
int ans[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		swap(a,b);
		if (a+b>n-2||a>b+1||b>a+1){
			puts("-1");
			continue;
		}
		if (a==b){
			int c=a+b+2;
			int tot=0;
			for (int i=c-1;i>=1;i-=2)ans[i]=++tot,ans[i+1]=++tot;
			for (int i=c+1;i<=n;i++)ans[i]=++tot;
		}
		if (a>b){
			int l=1,r=n;
			for (int i=1;i<=a;i++)ans[2*i-1]=r,ans[2*i]=l,l++,r--;
			for (int i=2*a+1;i<=n;i++)ans[i]=l,l++;
		}
		if (a<b){
			int l=1,r=n;
			for (int i=1;i<=b;i++)ans[2*i-1]=l,ans[2*i]=r,l++,r--;
			for (int i=2*b+1;i<=n;i++)ans[i]=r,r--;
		}
		for (int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}