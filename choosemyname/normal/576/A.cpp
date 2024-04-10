#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int prime(int i)
{
    for(int j=2;j*j<=i;j++)
        if(i%j==0)
            return 0;
        return 1;
}
vector<int> v;
int main()
{
    int n;
    cin>>n;
    for(int j=2;j<=n;j++)
    {
        if(prime(j))
        {
            for(int k=1,l=j;l<=n;k++,l*=j)
                v.push_back(l);
        }
    }
    cout<<v.size()<<endl;
    for(int j=0;j<v.size();j++)
        cout<<v[j]<<' ';
}