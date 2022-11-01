#include<iostream>
#include<map>
using namespace std;
#define R register int
#define L long long
inline void Solve(){
	int n,tm=1,x;
	cin>>n;
	map<L,int>S;
	L td=0,ans=0;
	for(R i=0;i!=n;i++){
		cin>>x;
		if(tm==1){
			while(S.empty()==false&&S.rbegin()->first+td>x){
				S.erase(S.rbegin()->first);
			}
		}else{
			while(S.empty()==false&&-S.begin()->first+td>x){
				S.erase(S.begin()->first);
			}
		}
		tm=-tm;
		td=x-td;
		S[(x-td)*tm]++;
		ans+=S[-td*tm];
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}