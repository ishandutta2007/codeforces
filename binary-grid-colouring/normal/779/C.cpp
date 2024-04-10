#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Price
{
	int a,b,c;
}price[200010];
int cmp(const Price &a, const Price &b)
{
	return a.c < b.c;
}
int main()
{
    int n,k;
    int ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
    	cin>>price[i].a;
	}
	for(int i=0;i<n;i++){
		cin>>price[i].b;
	}
	for(int i=0;i<n;i++){
		price[i].c = price[i].a - price[i].b;
	}
	sort(price,price+n,cmp);
	for(int i = 0; i < k;i++){
		ans += price[i].a;
	}
	for(int i=k; i < n; i++){
		if(price[i].c < 0) ans += price[i].a;
		else ans += price[i].b;
	}
	cout<<ans<<endl;
    return 0;
}