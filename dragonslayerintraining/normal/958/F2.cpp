#include <iostream>
using namespace std;
int cnt[200001];
int k[200001];
int n,m;


int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int i,j,sum=0,ans=2001001001,prev=0,arr[200001],C=0;
  cin>>n>>m;
  for (i=0;i<n;i++)
    cin>>arr[i];
  for (i=0;i<m;i++){
    cin>>k[i];
    if (k[i]==0)
      C++;
    sum+=k[i];
  }
  for (i=0;i<n;i++){
    if (i!=0){
      cnt[arr[i-1]]--;
      if (cnt[arr[i-1]]==k[arr[i-1]-1]-1)
	C--;      
    }
    for (j=max(i,prev);j<n;j++){
      //cout<<i<<' '<<j<<' '<<C<<endl;
      cnt[arr[j]]++;
      if (cnt[arr[j]]==k[arr[j]-1])
	C++;
      if (j-i+1>=sum){
	if (C==m){
	  ans=min(ans,j-i+1-sum);
	  cnt[arr[j]]--;
	  if (cnt[arr[j]]==k[arr[j]-1]-1)
	    C--;
	  break;
	}
      }
    }
    prev=min(j,n-1);
  }
  if (ans==2001001001)
    cout<<-1<<endl;
  else
    cout<<ans<<endl;
  return 0;
}