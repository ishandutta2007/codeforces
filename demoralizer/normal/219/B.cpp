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
	ll p,d,q;
	cin>>p>>d;q=p;
	for(ll i=1;;i*=10){
        p/=i;if(p==0)break;
        ll k=p%10;k=(k+1)%10;
        if(d>=k*i){q-=k*i;d-=k*i;}
        else break;
        p=q;
	}
	cout<<q;
}