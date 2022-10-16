#include<bits/stdc++.h>
using namespace std;
int n,a[103],w,b[103];
int main(){cin>>n>>w;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
		b[i]=(a[i]+1)/2,
		w-=b[i];
	if(w<0){cout<<-1;return 0;}
	while(w!=0){pair<int,int>x=make_pair(0,-1);
		for(int i=0;i<n;i++)
			if(a[i]!=b[i])
				x=max(x,make_pair(a[i],i));
		if(a[x.second]-b[x.second]>w)
			b[x.second]+=w,w=0;
		else
			w=w-a[x.second]+b[x.second],
			b[x.second]=a[x.second];
	}
	for(int i=0;i<n;i++)cout<<b[i]<<' ';
}