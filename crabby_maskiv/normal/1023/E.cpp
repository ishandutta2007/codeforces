#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=40005;
const ll mod=1000000007ll;
int n,m;
int x,y;
vector<pair<int,int> > v;
int main(){
	int i,j;
	cin>>n;
	x=n;y=n;
	while(x+y>n+1){
		cout<<"? 1 1 "<<x-1<<" "<<y<<endl;
		string ans;cin>>ans;
		if(ans=="YES") x--;
		else y--;
		//cout<<x<<y<<endl;
		v.push_back({x,y});
	}
	x=1;y=1;
	while(x+y<=n){
		v.push_back({x,y});
		cout<<"? "<<x<<" "<<y+1<<" "<<n<<" "<<n<<endl;
		string ans;cin>>ans;
		if(ans=="YES") y++;
		else x++;
	}
	v.push_back({n,n});
	sort(v.begin(),v.end());
	cout<<"! ";
	for(i=1;i<v.size();i++){
		if(v[i].second>v[i-1].second) cout<<"R";
		else cout<<"D";
	}
	fflush(stdout);
    return 0;
}