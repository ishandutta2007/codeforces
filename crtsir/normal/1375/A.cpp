#include<bits/stdc++.h>
using namespace std;
int T,n,a[99];
int main(){cin>>T;
	while(T--){cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)
			if(i%2==0)
				cout<<int(fabs(a[i]))<<' ';
			else
				cout<<int(-fabs(a[i]))<<' ';
		cout<<endl;
	}
}