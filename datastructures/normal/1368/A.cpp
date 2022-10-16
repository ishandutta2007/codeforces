#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <random>
using namespace std;
int t,n,a,b;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		int ans=0;
		for (int i=1;a<=n&&b<=n;i++){
			if (a>b)swap(a,b);
			a+=b;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}