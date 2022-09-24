#include <bits/stdc++.h>

using namespace std;

int n;
long long h[1001];
long long lis;

long long gcd(long long a,long long b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main()
{
	//TODO make some code
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	for (int p2=1;p2<n;++p2)
    {
        long long a1=p2,a2=h[p2]-h[0];
        long long g=gcd(a1,a2);
        a1/=g;
        a2/=g;
        lis=1000000001;
        bool moz=true;
        //cout<<p2<<endl;
        for (long long i=0;i<n;++i)
        {
            int ru=h[i]-h[0],gc=gcd(ru,i);
            if (h[i]*a1!=h[0]*a1+i*a2)
            {
                if (lis==1000000001)
                {
                    lis=i;
                }
                else if (h[i]*a1!=h[lis]*a1+(i-lis)*a2)
                {
                    moz=false;
                    //cout<<i<<' '<<a1<<' '<<a2<<endl;
                    break;
                }
            }
        }
        //cout<<endl<<endl;
        if (moz && lis!=1000000001)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    swap(h[0],h[1]);
    for (int p2=2;p2<n;++p2)
    {
        long long a1=p2-1,a2=h[p2]-h[0];
        long long g=abs(gcd(a1,a2));
        a1/=g;
        a2/=g;
        lis=1000000001;
        bool moz=true;
        //cout<<p2<<endl;
        for (long long i=0;i<n;++i)
        {
            //cout<<i<<' '<<h[i]<<' '<<h[0]<<' '<<a1<<' '<<a2<<endl;
            if (h[i]*a1!=h[0]*a1+(i-(i>0)-(i==1))*a2)
            {
                //cout<<h[i]*a1<<' '<<h[0]*a1<<' '<<(i-(i>0)-(i==1))<<' '<<(i-(i>0)-(i==1))*a2<<' '<<lis<<' '<<(i-lis+(lis==1))<<endl;
                if (lis==1000000001)
                {
                    lis=i;
                }
                else if (h[i]*a1!=h[lis]*a1+(i-lis+(lis==1))*a2)
                {
                    moz=false;
                    break;
                }
            }
        }
        //cout<<endl<<endl;
        if (moz && lis!=1000000001)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}