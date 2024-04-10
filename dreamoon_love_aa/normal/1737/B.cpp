# include <bits/stdc++.h>
#include <iostream>
using namespace std;
const long long mod=1e9+7;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,m,sum=0,sum2=0,sum1=0,count,l;
		cin>>n>>m;
           sum1=sqrt((long double)n);
          sum2=sqrt((long double)m);

          if(sum1==sum2){
          	if(sum1*sum1==n||n%sum1==0)
          		sum++;

         sum+=((m/sum1)-(n/sum2));
             //cout<<n<<" "<<m<<";";
             cout<<sum<<endl;
          }
          else{
          if(sum2-sum1>0){
          	if(sum1*sum1==n)
             {
             	sum=sum2-sum1;
             }
             else
             	sum=sum2-sum1-1;
             sum*=3;
      }
      //cout<<sum<<endl;
       
           if(sum1*sum1!=n){
           	sum1++;
          sum+=(((sum1*sum1)-1-n)/(sum1-1));
          sum++;
      }
   //cout<<sum<<endl;  
          sum+=((m-(sum2*sum2))/sum2);
          sum++;
       //cout<<n<<" "<<m<<";";
          cout<<sum<<endl;

  }

         // cout<<endl;    

   }
}