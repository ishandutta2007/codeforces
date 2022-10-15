#include <bits/stdc++.h>

using namespace std;

int i=-1;
int j=-1;

inline int mi(int p1,int p2)
{
    cout<<"? "<<p1<<" "<<p2<<endl;
    string res;
    cin>>res;
    if(res==">")
    {
        return p2;
    }
    else
    {
        return p1;
    }
}

inline void upd(int i2,int j2)
{
    int a=mi(i2,j2);
    int b=i2+j2-a; /// ma(i2,j2)
    if(i==-1)
    {
        i=a;
    }
    else
    {
        i=mi(i,a);
    }
    if(j==-1)
    {
        j=b;
    }
    else
    {
        j=j+b-mi(j,b);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        i=j=-1;
        int n;
        cin>>n;
        if(n%2==1)
        {
            i=n;
            j=n;
            n--;
        }
        for(int k=1;k<n+1-k;k++)
        {
            upd(k,n+1-k);
        }
        cout<<"! "<<i<<" "<<j<<"\n";
    }
    return 0;
}