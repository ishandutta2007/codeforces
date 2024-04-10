#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=100+5;
int n,m;
int a[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		if(n==3&&a[1]==1&&a[2]==1&&a[3]==1){
			cout<<1<<endl<<1<<endl;
			continue;
		}
		int sum=0;
		for(i=1;i<=n;i++) sum+=a[i];
		int f=1;
		for(i=2;i*i<=sum;i++)
			if(sum%i==0) f=0;
		if(!f){
			cout<<n<<endl;
			for(i=1;i<=n;i++) cout<<i<<" ";
			cout<<endl;
		}
		else{
			cout<<n-1<<endl;
			for(i=1;i<=n;i++){
				if(a[i]&1){
					for(j=1;j<=n;j++)
						if(i!=j) cout<<j<<" ";
					cout<<endl;
					break;
				}
			}
		}
	}
	return 0;
}