#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

int a[1000];
int n;

int calc(int cur)
{
    int i=0;
    int res=0;
    while (i<n)
        if (a[i]==cur)
        {
            i++;
            cur = (cur+1)%2;
        }
        else
        {
            res++;
            if (i+1<n && a[i+1]!=a[i])res++;
            i+=2;
        }
    return res;
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        char c;
        cin >> c;
        a[i] = c-'0';
    }
    int ans1=calc(1),ans0=calc(0);
    cout << min(ans1, ans0) << endl;
    return 0;
}