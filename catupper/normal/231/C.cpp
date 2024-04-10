#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long int sums[100000], n,k,a[100000],nbin = 1;

int main(){
  cin >> n >> k;
  for(long long int i = 0;i < n;i++)
    cin >> a[i];
  sort(a, a + n);
  sums[0] = a[0];
  for(long long int i = 1;i <n;i++)sums[i] = a[i] +sums[i - 1];
  long long int left = 0, len = 1, ansa = 1, ansb = a[0];
  while(left + len  <= n){
    long long int ts;
    if(left == 0) ts = sums[left + len - 1];
    else ts = sums[left + len - 1] - sums[left - 1];
    if(a[left + len - 1] * len - k <= ts){
      if(ansa < len){
	ansa = len;
	ansb = a[left + len - 1];
      }
      len++;
    }
    else{
      left++;
    }
  }

  cout <<  ansa << " " <<  ansb << endl;
  return 0;
}