/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int qu;
int num(int x){
	int cnt=0,cpy=x;
	while(cpy)cnt++,cpy/=10;
	int res=0,now=1;
	for(int i=1;i<cnt;i++)res+=i*((x-now+1)+(x-(now*10-1)+1))*(now*9)/2,now*=10;
	return res+cnt*((x-now+1)+1)*(x-now+1)/2;
}
int num0(int x){
	int cnt=0,cpy=x;
	while(cpy)cnt++,cpy/=10;
	int res=0,now=1;
	for(int i=1;i<cnt;i++)res+=i*(now*9),now*=10;
	return res+cnt*(x-now+1);
}
signed main(){
	cin>>qu;
	while(qu--){
		int x;
		cin>>x;
		int to=-1;
		for(int i=30;~i;i--)if(num(to+(1ll<<i))<x)to+=1ll<<i;
		x-=num(to);
		int ans=0;
		for(int i=30;~i;i--)if(num0(ans+(1ll<<i))<x)ans+=1ll<<i;
		x-=num0(ans);
		vector<int> dig;
		ans++;
		while(ans)dig.pb(ans%10),ans/=10;
		reverse(dig.begin(),dig.end());
		cout<<dig[x-1]<<"\n";
	}
	return 0;
}
/*1
5
1
3
20
38
56
*/
/*2
4
2132
506
999999999
1000000000
*/