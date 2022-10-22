/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
struct Hint{
	bool ne;int a,b;
	Hint(){ne=a=b=0;}
	friend Hint operator+=(Hint &x,int y){
		x.b+=x.ne?-y:y;
		x.a+=(x.b-(x.b%1000000000000ll+1000000000000ll)%1000000000000ll)/1000000000000ll;
		x.b=(x.b%1000000000000ll+1000000000000ll)%1000000000000ll;
//		cout<<x.a<<" "<<x.b<<"\n";
		if(x.a<0||x.b<0){
			x.ne^=1;
			x.a=-x.a;x.b=-x.b;
			x.a+=(x.b-(x.b%1000000000000ll+1000000000000ll)%1000000000000ll)/1000000000000ll;
			x.b=(x.b%1000000000000ll+1000000000000ll)%1000000000000ll;
//			cout<<"! "<<x.a<<" "<<x.b<<"\n";
		}
		return x;
	}
	void prt(){
//		cout<<ne<<" "<<a<<" "<<b<<"\n";
		if(!a&&!b)cout<<0;
		else if(!a)cout<<(ne?"-":"")<<b;
		else{
			cout<<(ne?"-":"")<<a;
			vector<int> v;
			int cpy=b;
			while(cpy)v.pb(cpy%10),cpy/=10;
			reverse(v.begin(),v.end());
			for(int i=v.size()+1;i<=12;i++)cout<<0;
			for(int i=0;i<v.size();i++)cout<<v[i];
		}
	}
};
int n;
signed main(){
	cin>>n;
	int sum=0;
	Hint ans;
	map<int,int> s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		sum+=x;
		s[x]++;
		ans+=x*i-sum-s[x-1]+s[x+1];
	}
	ans.prt();
	return 0;
}
/*1
5
1 2 3 1 3
*/
/*2
4
6 6 5 5
*/
/*3
4
6 6 4 4
*/