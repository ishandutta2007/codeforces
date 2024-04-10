#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int>>cnt;;
int main() {
	int n;
	cin>>n;
	cnt.resize(10000005);
	long long int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		cnt[arr[i]].push_back(i);
	}
	long long int mini=pow(10, 18);
	int first=-1;
	int last=-1;
	for(long long int g=1; g<=10000000; g++){
		vector<int>v;
		int cn=0;
		long long ans=pow(10, 18);
		for(long long int i=1; i*g<=10000000; i++){
			if(cn==0 && cnt[i*g].size()>=2){
				ans=(i*i*g);
				if(ans<mini){
					first=cnt[i*g][0];
					last=cnt[i*g][1];
					mini=ans;
				}
				break;
			}
			if(cn==0 && cnt[i*g].size()==1){
				v.push_back(cnt[i*g][0]);
				ans=g*i;
				cn++;
				continue;
			}
			if(cn==1 && cnt[i*g].size()>=1){
				ans=ans*i;
				if(ans<mini){
					mini=ans;
					first=v[0];
					last=cnt[i*g][0];
				}
				break;
			}
		}
	}
	cout<<min(first, last)+1<<" "<<max(first, last)+1;
	return 0;
}