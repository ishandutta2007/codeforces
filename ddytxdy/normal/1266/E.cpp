#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int n,q,a[N],m[N],ans[N];LL anss;
map<pair<int,int>,int>mp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),anss+=ans[i]=a[i];
	scanf("%d",&q);
	for(int i=1,x,y,z,p;i<=q;i++){
		scanf("%d%d%d",&x,&y,&z);
		pair<int,int>pp=make_pair(x,y);
		if((p=mp[pp]))m[p]--,anss-=ans[p],ans[p]=max(0,a[p]-m[p]),anss+=ans[p];
		if((p=mp[pp]=z))m[p]++,anss-=ans[p],ans[p]=max(0,a[p]-m[p]),anss+=ans[p];
		cout<<anss<<endl;
	}
	return 0;
}