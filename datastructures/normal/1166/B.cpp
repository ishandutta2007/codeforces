#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
string s="aeiou";
int n;
signed main(){
	cin>>n;
	for (int i=5;i<=n;i++){
		if (n%i==0&&n/i>=5){
			int r=i,c=n/i;
			int now=0;
			for (int j=1;j<=r;j++){
				now=j%5;
				for (int k=1;k<=c;k++){
					cout<<s[now];
					now=(now+1)%5;
				}
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}