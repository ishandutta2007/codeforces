#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
int a[N],b[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i]>>b[i];
		int l=1,r=n;
		while(l<r){
			int mid=l+r+1>>1;
			//x<=b[i] x>=mid-a[i]-1
			int mx=0;
			for(i=1;i<=n;i++){
				if(mx<=b[i]&&mx>=mid-a[i]-1) mx++;
			}
			if(mx>=mid) l=mid;
			else r=mid-1;
		}
		cout<<l<<endl;
	}
	return 0;
}