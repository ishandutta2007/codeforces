#include <bits/stdc++.h>
using namespace std;
long long m,n,k;
bool check(long long nu){
    long long kp=k;
    for(long long i=1; i<=n; i++){
        kp-=min(nu/i,m);
    }
    if(kp<1) return true;
    else return false;
}
int main()
{
    cin >> n >> m >> k;
    long long l=0,r=m*n+1;
    while(r-l>1){
        long long mid=(r+l)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    cout << r;
	return 0;
}