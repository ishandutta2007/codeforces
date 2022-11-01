#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int mi,cnt,n,a[100005],b[100005],c1[9]={1,0,-1,1,0,-1,1,0,-1},c2[9]={1,1,1,0,0,0,-1,-1,-1};
int ab(int n){
	if(n>=0){
		return n;
	}else{
		return 0-n;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	mi=12345678;
	for(int i=0;i<9;i++){
		b[1]=a[1]+c1[i];
		b[2]=a[2]+c2[i];
		cnt=0;
		if(i%3==0 || i%3==2){
			cnt++;
		}
		if(i<=2 || i>5){
			cnt++;
		}
		for(int j=3;j<=n;j++){
			b[j]=a[j];
		}
		bool can=1;
		int cha=b[2]-b[1];
		for(int j=2;j<n;j++){
			if(ab((b[j]+cha-b[j+1]))==1){
				b[j+1]=b[j]+cha;
				cnt++;
			}else{
				if(ab(b[j]+cha-b[j+1])>1){
					can=0;
					break;
				}
			}
		}
		if(can){
			mi=min(cnt,mi);
		}
	}
	if(mi==12345678){
		cout<<-1;
	}else{
		cout<<mi;
	}
	return 0;
}