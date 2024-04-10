#include<bits/stdc++.h>
using namespace std;
int cnt[5],l=-1;
int main(){
	cin>>cnt[0]>>cnt[1]>>cnt[2]>>cnt[3]>>cnt[4];
	while(cnt[0]>=0&&cnt[1]>=0&&cnt[2]>=0&&cnt[3]>=0&&cnt[4]>=0)
		cnt[0]-=1,
		cnt[1]-=1,
		cnt[2]-=2,
		cnt[3]-=7,
		cnt[4]-=4,l++;
	cout<<l;
}