#include<bits/stdc++.h>
using namespace std;
int n,q,a,cnt[32],pw[32]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,
1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int search(int a){
	int i=30;
	int ans=0;
	while(a){
		if(i==-1&&a)return -1;
		while((a<pw[i]||cnt[i]==0)&&i!=-1)i--;
		if(i==-1&&a)return -1;
		//cout<<a/pow(2,i)<<endl;
		int minv=min(int(a/pw[i]),cnt[i]);
		ans+=minv;
		a-=minv*pw[i];
		i--;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a;
		int tmp=0;
		while(a!=1)
			a=a/2,
			tmp++;
		cnt[tmp]++;
	}
	for(int i=0;i<q;i++){
		cin>>a;
		cout<<search(a)<<endl;
	}
}