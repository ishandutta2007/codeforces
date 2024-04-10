#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int w,h,u1,d1,u2,d2;
signed main(){
	cin>>w>>h>>u1>>d1>>u2>>d2;
	for (int i=h;i>=0;i--){
		w+=i;
		if (i==d1)w-=u1,w=max(w,0);
		if (i==d2)w-=u2,w=max(w,0);
	}
	cout<<w<<endl;
	return 0;
}