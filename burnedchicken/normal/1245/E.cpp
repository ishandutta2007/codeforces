#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int Mod=1e9+7;

int num(int x,int y){
	if(x%2==0) return (9-x)*10+9-y;
	else return (9-x)*10+y;
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int a;
	int ladder[100];
	loop(10){
		loopi(j,10) {
			cin >> a;
			ladder[num(i,j)]=num(i-a,j);
		}
	}
	double ans[100],ans1[100];
	double x,y;
	for(int i=99; i>=0; i--){
		if(i==99){
			ans[i]=ans1[i]=0;
			continue;
		}
		if(i>=94){
			ans[i]=ans1[i]=6;
			continue;
		}
		x=0;
		loopi(j,6) x+=ans[i+j+1];
		ans[i]=ans1[i]=x/6+1;
		if(ans[i]>ans1[ladder[i]]) ans[i]=ans1[ladder[i]];
		//cout << fixed << setprecision(10) << ans[i] << "\n";
	}
	cout << fixed << setprecision(10) << ans[0] << "\n";
	return 0;
}