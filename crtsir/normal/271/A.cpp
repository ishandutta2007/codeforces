#include<bits/stdc++.h>
using namespace std;
bool check(int x){set<int>s;
	while(x)s.insert(x%10),x/=10;
	return s.size()==4;
}
int main(){
	int n;cin>>n;n++;
	while(!check(n))n++;cout<<n;
}