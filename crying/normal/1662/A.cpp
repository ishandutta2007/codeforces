#include<bits/stdc++.h>
using namespace std;
int T,n,b,d,nw[13];
int main(){
	cin>>T;
	while(T--){
		memset(nw,-1,sizeof(nw));
		cin>>n;
		while(n--){
			cin>>b>>d;
			nw[d]=max(nw[d],b);
		}
		bool ok=1;
		int sum=0;
		for(int i=1;i<=10;i++)
			if(nw[i]!=-1)
				sum+=nw[i];
			else
				ok=0;
		if(ok)
			cout<<sum<<endl;
		else
			cout<<"MOREPROBLEMS\n";
	}
}