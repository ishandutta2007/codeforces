#include <bits/stdc++.h>
using namespace std;
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
       // merge(arr, l, m, r);
    }
}
int main() {	long long int n=0;	cin>>n;
           //long long int ans=findans(s+2);
           
           if(n>26||n==1)
           cout<<"YES\n";
           else{           	bool b=false;
           int ar[26];           for(int i=0;i<26;i++)
           {
           	  ar[i]=0;
           }
           for(int i=0;i<n;i++)
           {
           	  char c;           	  cin>>c;
           	  if(ar[c-97]>0){
           	  b=true;           	  break;
           	  }
           	  else
           	  ar[c-97]++;
           }
           if(b)
           cout<<"YES\n";
           else
           cout<<"NO\n";
           }
	return 0;
}