#include <bits/stdc++.h>

using namespace std;

long long n,a,b,c,d;

int main()
{
	//TODO make some code
	ios_base::sync_with_stdio(0);
	cin>>a>>b>>c>>d>>n;
	for (long long i=c;i<=d;++i)
    {
        if (i*n>=a && i*n<=b)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}