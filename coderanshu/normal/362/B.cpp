#include<bits/stdc++.h>
using namespace std ;
int main(int argc, char const *argv[])
{

    //freopen("inputf.in", "r", stdin);
    //freopen("outputf.in", "w", stdout);
    long int n,m,i,j;
    cin>>n>>m;
    long int a[m];
    for(i=0;i<m;i++)
    	cin>>a[i];
    sort(a,a+m);
    if(a[0]==1 || a[m-1]==n)
    {
    	cout<<"NO";
    	return 0;
    }
    for(i=0;i<m-1;i++)
    	a[i]=a[i+1]-a[i];
    bool ans =true;
    int count;
    for(i=0;i<m-1;i++)
    {
    	if(a[i]==1)
    	{
    		if(i<m-2 && a[i]==1 && a[i+1]==1)
    			ans=false;
    	}
    	if(ans==false)break;

    }
    if(ans)cout<<"YES";
    else cout<<"NO";


	return 0;
}