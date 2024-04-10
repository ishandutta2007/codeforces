#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,i=-1,j;
    cin>>n;
    char a[n+2];
    cin>>a;
    while(a[++i]=='.'){}
    j=i;
    while(a[++j]==a[i]){}
    if(a[j]=='.')
    {
        if(a[i]=='L'){i--;j--;swap(i,j);}
    }
    else{
        j--;
    }
   
    cout<<i+1<<" "<<j+1;
    return 0;
}