#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		cout<<'?'<<" ";
		for(int i=1;i<=100;i++){
			cout<<i<<" ";
		}
		cout<<endl;
		int a;
		cin>>a;
		cout<<'?'<<" ";
		for(int i=1;i<=100;i++){
			cout<<i*128<<" ";
		}
		cout<<endl;
		int b;
		cin>>b;
		int tot=0;
		for(int i=0;i<7;i++){
			if((b&(1<<i))>0)tot+=1<<i;
		}
		for(int i=7;i<14;i++){
			if((a&(1<<i))>0)tot+=1<<i;
		}
		cout<<"! "<<tot;
		return 0;
}