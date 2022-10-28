#include <iostream>


using namespace std;

int main()
{
    int a[100],n,t,i,j,sum1=0,sum2=0,count=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum2+=a[i];
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(sum1+a[i]>sum2-a[i])
        {
            count++;
            break;

        }
        else
        {
            sum2-=a[i];
            sum1+=a[i];
            count++;
        }
    }
    cout<<count;
    return 0;
}