#include  <bits/stdc++.h>
using namespace std;
double dis(double x1,double y1,double x2)
{
	return sqrt((x1-x2)*(x1-x2)+y1*y1);
}
int main()
{
	int n;
	double vb,vs;
	cin>>n>>vb>>vs;
	vector<pair<int,int>>vp;
	int k;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		vp.push_back(make_pair(k,i));
	}
	double xu,yu;
	cin>>xu>>yu;
	double ans2 = dis(xu,yu,vp[1].first);
	ans2=ans2/vs+vp[1].first/vb;
	int ans=2;
	for(int i=2;i<n;i++){
		double tmp = dis(xu,yu,vp[i].first)/vs + vp[i].first / vb ;
		if(tmp <= ans2){
			ans2=tmp;
			ans=vp[i].second+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}