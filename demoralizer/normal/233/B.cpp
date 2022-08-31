#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc secondll
#define vc vector
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n;
	cin>>n;
	ll a=(ll)sqrt(n/2)-2;
	if(a<1)a=1;
	if(n<100000000000)
	for(ll i=a;i*i<=n;i++){
        ll k=i,s=0;
        while(k>0){
            s+=k%10;
            k/=10;
        }
        if(i*i+s*i==n){cout<<i;return 0;}
	}
	else
    for(ll i=(ll)sqrt(n-100*(ll)sqrt(n))-10;i*i<=n;i++){
        ll k=i,s=0;
        while(k>0){
            s+=k%10;
            k/=10;
        }
        if(i*i+s*i==n){cout<<i;return 0;}
	}
	cout<<"-1";
}