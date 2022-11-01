#include <iostream>
using namespace std;

const long long mod=1000000007;
string s,t;
long long f[5001][5001];

int main()
{
    cin >> s >> t;
    int a=s.size(),b=t.size();
    long long sum=0;
    for(int o=a-1;o>=0;o--)
    {
        for(int i=b-1;i>=0;i--)
        {
            f[o][i]=f[o][i+1]+(s[o]==t[i])*(f[o+1][i+1]+1);
            if(f[o][i]>=mod) f[o][i]%=mod;
        }
        sum+=f[o][0];
        if(sum>=mod) sum%=mod;
    }
    cout << sum << endl;
    return 0;
}