#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a[n*n];
    int e;
    for(int i=0;i<n*n;i++)
    {
        cin>>a[i];
        if(a[i]==0) e=i;
    }
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    int r=floor(e/n);
    long long rsum=0;
    if(r!=0)for(int i=0;i<n;i++)rsum+=a[i];
    else for(int i=n;i<n*2;i++)rsum+=a[i];
    long long esum=0;
    for(int i=r*n;i<r*n+n;i++)esum+=a[i];
    long long tmp=rsum-esum;
    if(tmp<=0)cout<<-1<<endl;
    else
    {
        a[e]=tmp;
        bool leagal=true;
        for(int i=0;i<n;i++)
        {
            long long  sumtmp=0;
            for(int j=0;j<n;j++)sumtmp+=a[i*n+j];
            if(sumtmp!=rsum){leagal=false;break;}
        }
        for(int i=0;i<n;i++)
        {
            long long  sumtmp=0;
            for(int j=0;j<n;j++)sumtmp+=a[j*n+i];
            if(sumtmp!=rsum){leagal=false;break;}
        }
        long long sumtmp=0;
        for(int j=0;j<n;j++)sumtmp+=a[j*n+j];
        if(sumtmp!=rsum){leagal=false;}
        sumtmp=0;
        for(int j=0;j<n;j++)sumtmp+=a[j*n+(n-j-1)];
        if(sumtmp!=rsum){leagal=false;}
        if(leagal)cout<<tmp<<endl;
        else cout<<-1<<endl;
    }
}