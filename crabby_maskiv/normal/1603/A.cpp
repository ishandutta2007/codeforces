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
int a[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=n;i;i--){
			for(j=i;j;j--)
				if(a[j]%(j+1)) break;
			if(j==0) break;
			for(;j<i;j++) a[j]=a[j+1];
		}
		cout<<((i==0)?"YES":"NO")<<endl;
	}
	return 0;
}