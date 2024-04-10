#include <bits/stdc++.h>
using namespace std;
int K,iter=1;
int main(){
	cin>>K;
	if (K==0){
		cout<<"1 1\n114514";return 0;
	}
	for (;iter<=K;iter<<=1);
	cout<<"3 2\n";
	cout<<iter+K<<" "<<K<<"\n"<<iter<<" "<<iter+K<<"\n"<<iter<<" "<<K; 
}