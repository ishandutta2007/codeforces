#include <bits/stdc++.h> 
using namespace std;
int main(){
 ios_base::sync_with_stdio(false); 
 int d,n; 
 cin>>d>>n;
 int a[n];
 for(int i=0;i<n;i++) cin>>a[i];
 int b=1,c=1,i=0,k=0;
 for(;;b++,c=c%d+1){ 
 	abc:;
 	if(b==c){ 
 		c=a[i]%d;
 		i++; 
 		b=0; 
 		if(i==n)break;
 	} 
 	else{
 		if(c<b){
 			int r=b-c;
 			b+=r;
 			c=(c+2*r-1)%d+1;
 			k+=r;goto abc;
 		}
 		else{
 			int r=(d-c)/2;
 			b+=r;
 			c=(c+2*r-1)%d+1;
 			k+=r;
 			while(c>b){
 				c=(c+1)%d+1;k++;
 				b++;
 			}
 			goto abc;
 		}
 	} 
 }
 cout<<k;
}