#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		int ax,ay,bx,by,fx,fy; cin>>ax>>ay>>bx>>by>>fx>>fy;
		if(ax==bx&&ax==fx&&(fy-by)*(fy-ay)<0)printf("%d\n",abs(ay-by)+2);
		else if(ay==by&&ay==fy&&(fx-bx)*(fx-ax)<0)printf("%d\n",abs(ax-bx)+2);
		else printf("%d\n",abs(ax-bx)+abs(ay-by));
	}
}