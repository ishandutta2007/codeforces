#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
vector<vector<int>>ans;
int val=0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	int fr=0;
	if(n%2==1){
		fr=1;
	}
	
	for(int i=1; i<=n; i++){
		
		int pos=-1;
		for(int j=0;j<n; j++){
			if(arr[j]==i){
				pos=j;
				break;
			}
		}
		vector<int>temp;
		if(fr){
			if(pos!=0){
				temp.pb(pos);
			}
			
			temp.pb(n-pos-(i-1));
			
			for(int k=1; k<i; k++){
				temp.pb(1);
			}
			if(temp.size()==1){
				fr=1-fr;
				
				continue;
			}
			val++;
			ans.pb(temp);
		}
		else{
			
			for(int k=1; k<i; k++){
				temp.pb(1);
			}
			temp.pb(pos-i+2);
			if(pos!=(n-1)){
				temp.pb(n-pos-1);
			}
			if(temp.size()==1){
				fr=1-fr;
				continue;
			}
			val++;
			ans.pb(temp);
		}
		
		
		int ind1=0;
		vector<int>temp2;
		for(int j=0; j<temp.size(); j++){
			for(int k=ind1+temp[j]-1; k>=ind1; k--){
			
				temp2.pb(arr[k]);
				
			}
			ind1+=temp[j];
		
		}
		
		
		reverse(temp2.begin(), temp2.end());
		int xx=0;
		for(auto u:temp2){
			arr[xx]=u;
			xx++;
		}
		fr=1-fr;
	}

	cout<<val<<endl;
	
	for(auto u:ans){
		cout<<u.size()<<" ";
		for(auto u2:u){
			cout<<u2<<" ";
		}
		cout<<endl;
	}
	return 0;
}