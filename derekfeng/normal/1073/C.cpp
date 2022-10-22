#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
using namespace std;
int num1,num2,n,ex,ey,sx,sy;
string s;
int slay1[200004],slay2[200004],ans=0;
bool check(int x,int w){
	int go1=slay1[w]-slay1[x-1]+num1,go2=slay2[w]-slay2[x-1]+num2;
	if (abs(go1)+abs(go2)>w-x+1) return false;
	if (abs(go1)+abs(go2)==w-x+1) return true;
	if((w-x+1-abs(go1)-abs(go2))%2==0) return true;
	return false;
}
int main(){
	sx=0,sy=0;
	cin>>n>>s>>ex>>ey;
	for (int i=0;i<n;i++){
		if (s[i]=='U') sy++;
		if (s[i]=='D') sy--;
		if (s[i]=='L') sx--;
		if (s[i]=='R') sx++;
		slay1[i+1]=sx,slay2[i+1]=sy;
	}
	num1=ex-sx,num2=ey-sy;
	if (num1==0 && num2==0)
		return !printf("0");
	int ans=1e9;
	for (int i=1;i<=n;i++){
		int l=i,r=n+1;
		while (r>=l){
			int mid=(l+r)/2;
			if (l==n+1) break;
			if (check(i,mid)) r=mid-1;
			else l=mid+1;
		}
		if (r!=n+1) ans=min(ans,r-i+2);
	}
	if (ans!=1e9)return !printf("%d",ans);
	else cout<<"-1";
}