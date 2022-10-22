#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
int n,m,k;
vector<int> op;
int main(){
	int i,j;
	cin>>n;
	for(i=20;i>0;i--){
		if(!(n&(1<<i-1))){
			n^=(1<<i)-1;
			if(n==(1<<20)-1){
				cout<<op.size()*2+1<<endl;
				for(j=0;j<op.size();j++){
					cout<<op[j]<<" ";
				}	
				cout<<i;
				return 0;
			}
			n++;
			op.push_back(i);
		}
	}
	cout<<op.size()*2<<endl;
	for(i=0;i<op.size();i++){
		cout<<op[i]<<" ";
	}
	return 0;
}