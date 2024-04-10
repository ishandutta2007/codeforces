#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

map <int ,bool> m;
map <int ,int > a;
map <int ,int > b;
int x[maxn],s;
int n;
 
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		s=0;
		for(int j=0;j<k;j++){
			cin>>x[j];
			s+=x[j];
		} 
		for(int j=0;j<k;j++){
			if(m[s-x[j]]){
				cout<<"YES"<<endl;
				cout<<i+1<<' '<<j+1<<endl;
				cout<<a[s-x[j]]<<' '<<b[s-x[j]];
				return 0; 
			}
		}
		for(int j=0;j<k;j++){
			m[s-x[j]]=1;
			a[s-x[j]]=i+1;
			b[s-x[j]]=j+1;
		} 
	}
	cout<<"NO";
	return 0;
}