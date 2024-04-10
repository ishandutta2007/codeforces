#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>

int check(int n){
	int d=n%10;
	while(n>9)n/=10;
	return d==n;
}
int pow(int a,int b){
    if(b==0)return 1;
    int t=pow(a,b/2);
    if(b%2)return (a*t*t);
    else return (t*t);
}
int f(int n){
	while(!check(n))n--;
	int m=n,c=0;
	while(m!=0){
		m/=10;
		c++;
	}
	int ans=0;
	for(int i=1;i<c;i++){
		if(i==1)ans+=9;
		else ans+=9*pow(10,i-2);
	}
	if(c<2)return n;
	ans+=(n%10-1)*pow(10,c-2);
	int k=0;
	while(n>9){
		k=10*k+n%10;
		n/=10;
	}
	m=k;k=0;
	while(m>9){
		k=10*k+m%10;
		m/=10;
	}
	ans+=k+1;
	return ans;
}
void solve(){
    int l,r;
    cin>>l>>r;
    cout<<(f(r)-f(l-1));
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}