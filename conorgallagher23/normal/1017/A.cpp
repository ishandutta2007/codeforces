#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
using namespace std;
const int N=1e3+5;
int n;pii a[N];
bool cmp(pii a,pii b){
	if(a.first!=b.first)return a.first>b.first;
	return a.second<b.second; 
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y,z,h;i<=n;i++)scanf("%d%d%d%d",&x,&y,&z,&h),a[i]=pii(x+y+z+h,i);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)if(a[i].second==1){printf("%d\n",i);break;}
	return 0;
}