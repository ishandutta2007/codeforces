#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string x;
int n,a[105];
int main(){
//	freopen("1144A.in","r",stdin);
//	freopen("1144A.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x;
		for (int i=0;i<x.size();i++)a[i+1]=x[i]-'a'+1;
		sort(a+1,a+1+x.size());
		int flag=1;
		for (int i=2;i<=x.size();i++){
			if (a[i]-a[i-1]!=1){
				flag=0;
				break;
			}
		}
		if (flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
    	return 0;
}