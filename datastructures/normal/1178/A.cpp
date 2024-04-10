#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <ctime>
#include <random>
using namespace std;
int t,n,a[10005];
int main(){
	t=1;
	while(t--){
		cin>>n;
		int s1=0,s2=0;
		for (int i=1;i<=n;i++)cin>>a[i],s1+=a[i];
		s2=a[1];
		for (int i=2;i<=n;i++)
			if (a[i]<=a[1]/2)s2+=a[i];
		if (s2*2>s1){
			int num=1;
			for (int i=2;i<=n;i++)
				if (a[i]<=a[1]/2)num++;
			cout<<num<<endl;
			cout<<1<<' ';
			for (int i=2;i<=n;i++)
				if (a[i]<=a[1]/2)cout<<i<<' ';
			cout<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}