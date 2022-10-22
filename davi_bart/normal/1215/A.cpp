#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		int a,b,a1,b1,N;
		cin>>a>>b>>a1>>b1>>N;
		if(a1>b1){
			swap(a,b);
			swap(a1,b1);
		}
		int tot=a*a1+b*b1;
		tot-=a+b;
		if(tot>=N)cout<<0<<" ";
		else cout<<N-tot<<" ";
		int ma=min(N/a1,a);
		N-=a1*min(N/a1,a);
		cout<<ma+N/b1;
		return 0;
}