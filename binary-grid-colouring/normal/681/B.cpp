#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long num1 = 1234567;
    long long num2 = 123456;
    long long num3 = 1234;
    for(long long i=0;i<=100;i++)
        for(long long j=0;j<=10000;j++)
            if(n>=i*num1+j*num2)
            {
                long long p = n - i*num1-j*num2;
                if(p%num3==0)
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }

    cout<<"NO"<<endl;
}