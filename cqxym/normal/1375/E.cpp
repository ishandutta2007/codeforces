#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
int a[1000],id[1000];
vector<int>V[1000];
int main(){
	int n,x;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
		id[i]=i;
	}
	auto Compare=[](int x,int y){
		if(a[x]==a[y]){
			return x<y;
		}
		return a[x]<a[y];
	};
	sort(id,id+n,Compare);
	vector<pair<int,int>>E;
	for(R i=0;i!=n;i++){
		for(int j=n-1;j!=i;j--){
			if(a[j]<a[i]){
				V[i].push_back(j);
			}
		}
	}
	for(R i=0;i!=n;i++){
		x=id[i];
		for(int T:V[x]){
			E.push_back(make_pair(x,T));
		}
	}
	cout<<E.size();
	for(auto T:E){
		cout<<endl<<T.first+1<<" "<<T.second+1;
	}
	return 0;
}