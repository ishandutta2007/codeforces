#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
vector<int>S[1000];
int ans[1000];
inline void Solve(){
	int n,k,c,x;
	cin>>n>>k;
	for(R i=0;i!=k;i++){
		cin>>c;
		S[i].clear();
		for(R j=0;j!=c;j++){
			cin>>x;
			S[i].push_back(x);
		}
	}
	int totmax;
	cout<<"? "<<n;
	for(R i=1;i<=n;i++){
		cout<<' '<<i;
	}
	cout<<endl;
	cout.flush();
	cin>>totmax;
	int l=1,r=n,mid,curmax;
	while(l<r){
		mid=l+r>>1;
		cout<<"? "<<mid-l+1;
		for(R i=l;i<=mid;i++){
			cout<<' '<<i;
		}
		cout<<endl;
		cout.flush();
		cin>>curmax;
		if(curmax<totmax){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	for(R i=0;i!=k;i++){
		int tag=false;
		for(vector<int>::iterator T=S[i].begin();T!=S[i].end();T++){
			if(*T==r){
				tag=true;
				break;
			}
		}
		if(tag==true){
			cout<<"? "<<n-S[i].size();
			vector<int>::iterator T=S[i].begin();
			sort(T,S[i].end());
			for(R j=1;j<=n;j++){
				if(T==S[i].end()||j!=*T){
					cout<<' '<<j;
				}else{
					T++;
				}
			}
			cout<<endl;
			cout.flush();
			cin>>ans[i];
		}else{
			ans[i]=totmax;
		}
	}
	cout<<'!';
	for(R i=0;i!=k;i++){
		cout<<' '<<ans[i];
	}
	cout<<endl;
	string P;
	cin>>P;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}