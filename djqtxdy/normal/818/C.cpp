#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}
vector<int> up,down,lf,rg;
vector<pair<pair<int,int>,pair<int,int> > > vv;
int main(){
	int d,n,m;
	scanf("%d %d %d",&d,&n,&m);
	for (int i=0;i<d;i++){
		int ax,ay,bx,by;
		scanf("%d %d %d %d",&ax,&ay,&bx,&by);
		vv.pb(mp(mp(ax,ay),mp(bx,by)));
		lf.pb(min(ax,bx));
		rg.pb(max(ax,bx));
		up.pb(min(ay,by));
		down.pb(max(ay,by));
	}
	sort(lf.begin(),lf.end());
	sort(rg.begin(),rg.end());
	sort(down.begin(),down.end());
	sort(up.begin(),up.end());
	int cl,cr,cu,cd;
	scanf("%d %d %d %d",&cl,&cr,&cu,&cd);
	for (int i=0;i<d;i++){
		int x=vv[i].first.first,y=vv[i].first.second,_x=vv[i].second.first,_y=vv[i].second.second;
		int v1=lower_bound(lf.begin(),lf.end(),max(x,_x))-lf.begin();
		int v2=upper_bound(rg.begin(),rg.end(),min(x,_x))-rg.begin();
		v2=rg.size()-v2;
		int v3=upper_bound(down.begin(),down.end(),min(y,_y))-down.begin();
		v3=down.size()-v3;
		int v4=lower_bound(up.begin(),up.end(),max(y,_y))-up.begin();
		if (_x!=x){
			v1--;
			v2--;
		}
		else{
		v3--;v4--;
		}
	//	cout<<v1<<v2<<v3<<v4<<endl;
		if (v1==cl && v2==cr && v3==cd && v4==cu){
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}