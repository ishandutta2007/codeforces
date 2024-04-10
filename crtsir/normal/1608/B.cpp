#include<bits/stdc++.h>
using namespace std;
int T=1,n,a,b;
int main(){
	cin>>T;
	while(T--){
		scanf("%d%d%d",&n,&a,&b);
		int m;
		if(fabs(a-b)>1){
			cout<<-1<<endl;
			continue;
		}
		if(a==b){
			m=2+2*a;
			if(m>n){
				cout<<-1<<endl;
				continue;
			}
			for(int i=0;i<m;i++)
				if(i%2==0)
					cout<<i/2+1<<' ';
				else
					cout<<i/2+m/2+1<<' ';
			for(int i=m;i<n;i++)
				cout<<i+1<<' ';
			cout<<endl;
		}else{
			m=max(a,b)*2+1;
			if(m>n){
				cout<<"-1\n";
				continue;
			}
			if(a>b){
				int cnt=0;
				for(int i=m;i<n;i++)
					cout<<i-m+1<<' ',cnt++;
				cout<<1+cnt<<' ';
				for(int i=0;i<m/2;i++)
					cout<<cnt+i*2+3<<' '<<cnt+i*2+2<<' ';
				cout<<endl;
			}else{
				int cnt=0;
				for(int i=m;i<n;i++)
					cout<<n-i+m<<' ',cnt++;
				cout<<n-cnt<<' ';
				for(int i=0;i<m/2;i++)
					cout<<n+1-(cnt+i*2+3)<<' '<<n+1-(cnt+i*2+2)<<' ';
				cout<<endl;
			} 
		}
	}
}