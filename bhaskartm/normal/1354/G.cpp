#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	srand(time(0));
	while(t--){
		int n, k;
		cin>>n>>k;
		bool b=1;
		for(int i=0; i<15; i++){
			cout<<"?"<<" "<<1<<" "<<1<<endl;
			cout<<1<<endl;
			int x=1;
			while(x==1){
				x=(rand()%n)+1;
			}
			cout<<x<<endl;
			string s;
			cin>>s;
			if(s=="SECOND"){
				cout<<"!"<<" "<<1<<endl;
				b=0;
				break;
			}
		}
		if(b==0){
			continue;
		}
		int l=1;
		bool c=1;
		while(2*l<=n){
			cout<<"?"<<" "<<l<<" "<<l<<endl;
			for(int i=1; i<=l; i++){
				cout<<i<<" ";
			}
			cout<<endl;
			for(int i=1; i<=l; i++){
				cout<<i+l<<" ";
			}
			cout<<endl;
			string s;
			cin>>s;
			if(s=="FIRST"){
				c=0;
				break;
			}
			l=2*l;
		}
		if(c==0){
			int lo=1;
			int hi=l;
			int ans=-1;
			while(lo<=hi){
				int mid=(lo+hi)/2;
				cout<<"?"<<" "<<mid<<" "<<mid<<endl;
				for(int i=l-mid+1; i<=l; i++){
					cout<<i<<" ";
				}
				cout<<endl;
				for(int i=l+1; i<=l+mid; i++){
					cout<<i<<" ";
				}
				cout<<endl;
				string s;
				cin>>s;
				if(s=="EQUAL"){
					lo=mid+1;
				}
				else{
					hi=mid-1;
					ans=mid;
				}
			}
			cout<<"!"<<" "<<ans+l<<endl;
			continue;
		}
		else{
			int lo=1;
			int hi=n-l;
			int ans=-1;
			while(lo<=hi){
				int mid=(lo+hi)/2;
				cout<<"?"<<" "<<mid<<" "<<mid<<endl;
				for(int i=l-mid+1; i<=l; i++){
					cout<<i<<" ";
				}
				cout<<endl;
				for(int i=l+1; i<=l+mid; i++){
					cout<<i<<" ";
				}
				cout<<endl;
				string s;
				cin>>s;
				if(s=="EQUAL"){
					lo=mid+1;
				}
				else{
					hi=mid-1;
					ans=mid;
				}
			}
			cout<<"!"<<" "<<ans+l<<endl;
			continue;
		}
	}
	return 0;
}