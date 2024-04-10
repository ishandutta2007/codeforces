/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
#define X first
#define Y second
#define mp make_pair
const int N=1000000;
int n;
vector<pair<pair<int,int>,double> > v; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		v.pb(mp(mp(i,i),1.*x));
		while(v.size()>=2){
			pair<pair<int,int>,double> a=v[v.size()-2],b=v.back();
//			printf("([%d,%d],%.5lf) ([%d,%d],%.5lf)\n",a.X.X,a.X.Y,a.Y,b.X.X,b.X.Y,b.Y);
			if(b.Y<a.Y)v.ppb(),v.ppb(),v.pb(mp(mp(a.X.X,b.X.Y),((a.X.Y-a.X.X+1)*a.Y+(b.X.Y-b.X.X+1)*b.Y)/(b.X.Y-a.X.X+1)));
			else break;
		}
	}
	for(int i=0;i<v.size();i++){
		pair<pair<int,int>,double> x=v[i];
		for(int j=x.X.X;j<=x.X.Y;j++)printf("%.100lf\n",x.Y);
	}
	return 0;
}