#include<bits/stdc++.h>
using namespace std;
vector<pair<double,int> >v;
int main(){
	int n;double x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",&x);
		int cnt=1;
		while(v.size()&&x<v.back().first){
			x=x*cnt+v.back().first*v.back().second;
			cnt+=v.back().second;
			x/=cnt;
			v.pop_back();
		}
		v.push_back(make_pair(x,cnt));
	} 
	for(int i=0;i<v.size();i++)
		for(int j=0;j<v[i].second;j++)
			printf("%.9lf ",v[i].first);
}