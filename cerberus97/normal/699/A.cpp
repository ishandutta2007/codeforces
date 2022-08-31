#include<iostream>
using namespace std;
int main()
{
long long int n,b=0,c=0,mini,i,a[200006],ar[200006],j;
char s[200006];
cin>>n>>s;
ar[0]=0;
for(i=0;i<n;i++)
{cin>>a[i];}
for(j=0;j<n-1;j++)
{
if(s[j]=='R' && s[j+1]=='L')
{
c++;
ar[b]=a[j+1]-a[j];
b++;
}
}
mini=ar[0];
for(long long int c=0;c<b;c++)
{
mini=min(mini,ar[c]);}
if(c==0)
{cout<<-1;}
else
{cout<<(mini/2);}
}