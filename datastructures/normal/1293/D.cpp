#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#define int long long
#define inf 50000000000000000 
using namespace std;
inline int dis(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}
int n,t,x[1005],y[1005],ax,ay,bx,by;
inline bool check(int l,int r){
	int nowt=0;
	nowt+=min(dis(x[0],y[0],x[l],y[l]),dis(x[0],y[0],x[r],y[r]));
	if (nowt>t)return 0;
	for (int i=l+1;i<=r;i++){
		nowt+=dis(x[i-1],y[i-1],x[i],y[i]);
		if (nowt>t)return 0;
	}
	return 1;
}
signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	n=1;
	cin>>x[1]>>y[1]>>ax>>ay>>bx>>by;
	cin>>x[0]>>y[0]>>t;
	while(x[n]<=inf&&y[n]<=inf){
		n++;
		x[n]=x[n-1]*ax+bx,y[n]=y[n-1]*ay+by;
	}
	int c=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++){
			if (check(i,j))c=max(c,j-i+1);
		}
	cout<<c<<endl;
	return 0;
}