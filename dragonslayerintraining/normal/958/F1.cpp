#include <iostream>
using namespace std;

int main()
{
  int m,n,arr[101],k[101];
  int i,j,l;
  int cnt[101];
  cin>>n>>m;
  for (i=0;i<n;i++)
    cin>>arr[i];
  for (i=0;i<m;i++)
    cin>>k[i];
  for (i=0;i<n;i++){
    for (j=1;j<=m;j++)
      cnt[j]=0;
    for (j=i;j<n;j++){
      cnt[arr[j]]++;
      for (l=0;l<m;l++)
	if (k[l]!=cnt[l+1])
	  break;
      if (l==m){
	cout<<"YES"<<endl;
	return 0;
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}