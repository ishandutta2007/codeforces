/******************
*  Author: BD747  *
******************/
#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;

const int date[]={0,0,31,60,91,121,152,182,213,244,274,305,335};

int a[5000005][6];
int tim[5000005];
int n,m;
int cnt;
char buf[5000005];
int ans;

int main(){
	
	cin>>n>>m;
	cnt++;
	while(scanf("%d-%d-%d %d:%d:%d",&a[cnt][0],&a[cnt][1],&a[cnt][2],&a[cnt][3],&a[cnt][4],&a[cnt][5]) != EOF){
		gets(buf);
		tim[cnt]=(((date[a[cnt][1]]+a[cnt][2]-1)*24+a[cnt][3])*60+a[cnt][4])*60+a[cnt][5];
		cnt++;
	}
	
	for(int i=1;i<cnt;i++){
		ans=0;
		for(int j=i;j>=1;j--){
			if(tim[i]-tim[j]<n){
				ans++;
			}else{
				break;
			}
		}
		if(ans>=m){
			printf("%d-",a[i][0]);
			if(a[i][1]<10)printf("0");
			printf("%d-",a[i][1]);
			if(a[i][2]<10)printf("0");
			printf("%d ",a[i][2]);
			if(a[i][3]<10)printf("0");
			printf("%d:",a[i][3]);
			if(a[i][4]<10)printf("0");
			printf("%d:",a[i][4]);
			if(a[i][5]<10)printf("0");
			printf("%d\n",a[i][5]);
			return 0;
		}
	}
	
	puts("-1");
	
	return 0;
}