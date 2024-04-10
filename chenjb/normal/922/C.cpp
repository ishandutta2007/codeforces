#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
long long n,k;
set<int> dic;
int main()
{
    cin>>n>>k;
    dic.clear();
    for(long long i=1;i<=k;i++)
            if (dic.find(n%i)!=dic.end())
            {
                puts("No");
                return 0;
            }else dic.insert(n%i);
    puts("Yes");
    return 0;
}