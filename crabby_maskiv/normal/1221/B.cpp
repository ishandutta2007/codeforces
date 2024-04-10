#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
const int M=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=1000000007ll;
int n,m;

int main(){
    ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			if((i&1)^(j&1)) cout<<"W";
			else cout<<"B";
		cout<<endl;
	}
    return 0;
}