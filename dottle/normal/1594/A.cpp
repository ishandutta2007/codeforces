#include<bits/stdc++.h>
#define int long long
//const int N=
using namespace std;

int t,n; 

main(){
	ios::sync_with_stdio(false);
	cin>>t;while(t--){
		cin>>n;
		if(n==1)cout<<"0 1\n";
		else{
			n*=2;
			for(int i=1;i;i++){
				if(n%i==0){
					int x=i,y=n/i;
					if((x+y&1)){					
						cout<<-y/2+1<<' '<<y/2<<endl;
						break;
					}
				} 
			}
		}
	}
}