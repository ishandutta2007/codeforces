#include<bits/stdc++.h>
using namespace std;
int poly[100010],idx=0;
int well(int n,int k){
	long long ans=0;
	
	for(int i=n;i>=0;i--){
		ans=ans*(long long)k+(long long)poly[i];
		if(ans>10000000000||ans<-10000000000) return 0;
	}
	if(ans==0) return 1;
	return 0;
}
int main(){
	int n,k,unknown=0;
	char tmp[10];
	int position;
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++){
		scanf("%s",&tmp);
		if(tmp[0]=='?'){
			unknown++;
			position=i;
			if(i==0) idx=1;
		}
		poly[i]=atoi(tmp);
	
	}
	if(k==0){
		if(idx){
			if((n+1-unknown)%2==0) printf("No");
			else printf("Yes");
		}
		else{
			if(poly[0]==0) printf("Yes");
			else printf("No");
		}
	} 
	else if(unknown>=1) {
		if(n%2==0) printf("No");
		else printf("Yes");
	}
	
	else{
		
		if(k==1){
			long long sum=0;
			for(int i=0;i<=n;i++){
				sum+=(long long)poly[i];
			}
			if(sum==0) printf("Yes");
			else printf("No");
		}
		else if(k==0){
			if(poly[0]==0) printf("Yes");
			else printf("No");
		}
		else if(k==-1){
			long long sum=0;
			for(int i=0;i<=n;i++){
				if(i%2==0) sum+=(long long)poly[i];
				else sum-=(long long)poly[i];
			}
			if(sum==0) printf("Yes");
			else printf("No");
		}
		else {
			if(well(n,k)) printf("Yes");
			else printf("No");
		}
	}
	return 0;
}