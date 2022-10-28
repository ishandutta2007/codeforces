#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin>>k;
	string s="codeforces";
	int val=1;
	int arr[10];
	for(int i=0; i<10; i++){
		arr[i]=1;
	}
	int num=1;
	int pt=0;
	while(num<k){
		arr[pt]++;
		num=(num*(arr[pt]))/(arr[pt]-1);
		pt++;
		pt=pt%10;
	}
	for(int i=0; i<10; i++){
		for(int j=0; j<arr[i]; j++){
			cout<<s[i];
		}
	}
	return 0;
}