#include<bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string a;
	cin>>a;
	int count=0;
	int mi=0;
	for(int i=0;i<n;i++){
		if(a[i]=='-'){
			count-=1;
		}
		else{
			count+=1;
		}
		mi=min(mi,count);
	}
	printf("%d\n",mi*-1+count);
}