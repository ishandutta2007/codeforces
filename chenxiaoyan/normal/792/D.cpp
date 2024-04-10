/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,qu;
int two(int x){
	int cnt=0;
	while(!(x&1))cnt++,x>>=1;
	return cnt;
}
signed main(){
	cin>>n>>qu;
	n=log2(n+1);
	while(qu--){
		int x;
		string a;
		cin>>x>>a;
		for(int i=0;i<a.size();i++)
			if(a[i]=='U'){
				if(two(x)==n-1)continue;
				int y=x+(1ll<<two(x));
				if(y>=1ll<<n||two(y)!=two(x)+1)x-=1ll<<two(x);
				else x+=1ll<<two(x);
			}
			else if(a[i]=='L'){
				if(two(x)==0)continue;
				x-=1ll<<two(x)-1;
			}
			else{
				if(two(x)==0)continue;
				x+=1ll<<two(x)-1;
			}
		cout<<x<<"\n";
	}
	return 0;
}