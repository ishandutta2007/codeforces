#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>>vec;int n,a;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;vec.push_back(make_pair(a,i));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size()/2;i++)cout<<vec[i].second+1<<' '<<vec[vec.size()-1-i].second+1<<endl;
	return 0;
}